#include "uart_polling.h"
#include "stm32f446xx.h"
#include "rx_ring_buffer.h"

static rx_ring_buffer_t s_rx_buffer;

void uart_init(uint32_t peripheral_clock_hz, uint32_t baud_rate)
{
    rx_ring_buffer_init(&s_rx_buffer);
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    GPIOA->MODER &= ~(GPIO_MODER_MODER2 | GPIO_MODER_MODER3);
    GPIOA->MODER |= (GPIO_MODER_MODER2_1 | GPIO_MODER_MODER3_1);

    GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR2 | GPIO_OSPEEDER_OSPEEDR3);
    GPIOA->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR2_1 | GPIO_OSPEEDER_OSPEEDR3_1);

    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD2 | GPIO_PUPDR_PUPD3);
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD3_0;

    GPIOA->AFR[0] &= ~((0xFU << (2U * 4U)) | (0xFU << (3U * 4U)));
    GPIOA->AFR[0] |=  ((0x7U << (2U * 4U)) | (0x7U << (3U * 4U)));

    USART2->CR1 &= ~USART_CR1_UE;
    USART2->CR1 &= ~(USART_CR1_OVER8 | USART_CR1_M | USART_CR1_PCE);
    USART2->CR2 &= ~USART_CR2_STOP;

    if (baud_rate > 0U) {
        USART2->BRR = (peripheral_clock_hz + (baud_rate / 2U)) / baud_rate;
    }

    USART2->CR1 |= (USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE | USART_CR1_UE);

    NVIC_SetPriority(USART2_IRQn, 2U);
    NVIC_EnableIRQ(USART2_IRQn);
}

void uart_write_byte(uint8_t byte)
{
    while (!(USART2->SR & USART_SR_TXE)) {
    }
    USART2->DR = (uint32_t)byte;
}

bool uart_rx_get_byte(uint8_t *out_byte)
{
    if (out_byte == 0) {
        return false;
    }
    NVIC_DisableIRQ(USART2_IRQn);
    bool status = rx_ring_buffer_pop(&s_rx_buffer, out_byte);
    NVIC_EnableIRQ(USART2_IRQn);
    return status;
}

void USART2_IRQHandler(void)
{
    if ((USART2->SR & USART_SR_RXNE) && (USART2->CR1 & USART_CR1_RXNEIE)) {
        uint8_t rx_byte = (uint8_t)(USART2->DR & 0xFFU);
        (void)rx_ring_buffer_push(&s_rx_buffer, rx_byte);
    }
}
