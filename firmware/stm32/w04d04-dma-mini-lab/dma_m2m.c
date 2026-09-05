#include "dma_m2m.h"
#include "stm32f446xx.h"
#include <stdint.h>

/* Cấu trúc lưu kết quả quan sát thực nghiệm */
typedef struct {
    uint32_t dst_snapshot[4];
    uint32_t ndtr_final;
    uint32_t en_final;
    uint32_t tcif;
    uint32_t teif;
    uint32_t feif;
    uint32_t timed_out;
} dma_result_t;

volatile dma_result_t g_dma_result;

void dma_m2m_experiment(const dma_m2m_request_t *request)
{
    /*
     * Mini-lab W04D04: Cố ý sử dụng dữ liệu hard-coded nội bộ (src/dst tĩnh trong RAM)
     * để kiểm chứng luồng hoạt động bare-metal của DMA2 M2M.
     * Tham số request tạm thời chưa dùng tới và sẽ được tích hợp sau khi hoàn tất lab nền.
     */
    (void)request;

    /* 1. Dữ liệu thử nghiệm đặt trong RAM */
    static uint32_t src[4] = {10, 20, 30, 40};
    static volatile uint32_t dst[4] = {0, 0, 0, 0};

    /* 2. Cấp clock cho DMA2 trên bus AHB1 */
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

    /* 3. Tắt Stream 0 trước khi ghi cấu hình */
    DMA2_Stream0->CR &= ~DMA_SxCR_EN;
    while (DMA2_Stream0->CR & DMA_SxCR_EN) {
        /* Chờ hardware clear bit EN */
    }

    /* 4. Xóa toàn bộ cờ ngắt cũ của Stream 0 */
    DMA2->LIFCR = DMA_LIFCR_CTCIF0  |
                  DMA_LIFCR_CHTIF0  |
                  DMA_LIFCR_CTEIF0  |
                  DMA_LIFCR_CDMEIF0 |
                  DMA_LIFCR_CFEIF0;

    /* 5. Gán địa chỉ nguồn, đích, số lượng item và cấu hình FIFO */
    DMA2_Stream0->PAR  = (uint32_t)(uintptr_t)src;
    DMA2_Stream0->M0AR = (uint32_t)(uintptr_t)dst;
    DMA2_Stream0->NDTR = 4;

    /* Bật FIFO: DMDIS = 1, FIFO threshold full */
    DMA2_Stream0->FCR = DMA_SxFCR_DMDIS | DMA_SxFCR_FTH;

    /* 6. Cấu hình CR: M2M, PINC=1, MINC=1, PSIZE=32-bit, MSIZE=32-bit */
    DMA2_Stream0->CR = (2U << DMA_SxCR_DIR_Pos)   |
                       DMA_SxCR_PINC              |
                       DMA_SxCR_MINC              |
                       (2U << DMA_SxCR_PSIZE_Pos) |
                       (2U << DMA_SxCR_MSIZE_Pos);

    /* 7. Kích hoạt transfer */
    DMA2_Stream0->CR |= DMA_SxCR_EN;

    /* 8. Polling dừng khi có TCIF0, TEIF0, FEIF0 hoặc hết timeout */
    uint32_t timeout = 1000000U;
    const uint32_t exit_mask = DMA_LISR_TCIF0 | DMA_LISR_TEIF0 | DMA_LISR_FEIF0;

    while (!(DMA2->LISR & exit_mask) && (--timeout > 0)) {
        /* Polling */
    }

    /* 9. Teardown an toàn: Nếu còn EN do timeout hoặc lỗi, cưỡng chế disable */
    if (DMA2_Stream0->CR & DMA_SxCR_EN) {
        DMA2_Stream0->CR &= ~DMA_SxCR_EN;
        while (DMA2_Stream0->CR & DMA_SxCR_EN) {
            /* Chờ stream ngắt hoàn toàn để bảo vệ lifetime của buffer */
        }
    }

    /* 10. Chụp snapshot trạng thái thực tế */
    uint32_t lisr = DMA2->LISR;
    g_dma_result.tcif       = (lisr & DMA_LISR_TCIF0) ? 1U : 0U;
    g_dma_result.teif       = (lisr & DMA_LISR_TEIF0) ? 1U : 0U;
    g_dma_result.feif       = (lisr & DMA_LISR_FEIF0) ? 1U : 0U;
    g_dma_result.ndtr_final = DMA2_Stream0->NDTR;
    g_dma_result.en_final   = (DMA2_Stream0->CR & DMA_SxCR_EN) ? 1U : 0U;
    g_dma_result.timed_out  = (timeout == 0) ? 1U : 0U;

    for (int i = 0; i < 4; i++) {
        g_dma_result.dst_snapshot[i] = dst[i];
    }

    /* 11. Xóa sạch cờ sau khi hoàn tất snapshot */
    DMA2->LIFCR = DMA_LIFCR_CTCIF0 | DMA_LIFCR_CTEIF0 | DMA_LIFCR_CFEIF0;
}
