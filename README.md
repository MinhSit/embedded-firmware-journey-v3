 # Embedded Firmware Journey V3

Hành trình học Embedded/Firmware theo hướng competency-first: ưu tiên năng lực thật, kiểm thử có bằng chứng và khả năng giải thích độc lập.

## Timeline

- Sprint 0: 09/08/2026
- Week 1 bắt đầu: 10/08/2026
- Project v1.0 hard deadline: 14/12/2026
- Roadmap kết thúc: 12/01/2027

## Mục tiêu

Xây dựng năng lực và portfolio đủ mạnh để ứng tuyển các vị trí:

- Embedded/Firmware Intern
- Embedded Software / IoT Intern
- Firmware Validation / Test Intern
- R&D Intern / Trainee có công việc kỹ thuật thực tế

Các năng lực chính của roadmap:

- Embedded C
- STM32 / Cortex-M
- GPIO, EXTI, UART, Timer/PWM, I2C, SPI, CAN
- Interrupt và debugging
- FreeRTOS và concurrency
- Host testing và CI
- STM32/FreeRTOS Data Logger
- STM32–ESP32 communication protocol
- Wi-Fi và MQTT
- MQTT over TLS
- ESP32 HTTPS OTA A/B
- Rollback và resilience testing
- Fault injection và soak testing
- Technical documentation
- Project defense và interview preparation

## Nguyên tắc cốt lõi

Ba khái niệm sau luôn được tách riêng:

1. Artifact completion
2. Test completion
3. Competency verification

Một artifact chạy được hoặc PASS toàn bộ test không tự động chứng minh competency.

Competency cốt lõi phải được xác minh bằng independent gate theo SYSTEM_SPEC_V3.

## AI Integrity

AI được sử dụng như công cụ học tập, review và debugging, nhưng không được âm thầm thay thế tư duy của người học.

Các mức hỗ trợ:

- AI-0: Independent / closed-book
- AI-1: Theory / clarification
- AI-2: Hint
- AI-3: Review / debugging sau meaningful attempt
- AI-4: Implementation patch
- AI-5: Full/reference solution

AI-4 hoặc AI-5 có thể giúp hoàn thành artifact, nhưng competency bị ảnh hưởng phải được kiểm tra lại bằng fresh AI-0 gate.

Chi tiết xem:

`docs/system/SYSTEM_SPEC_V3.md`

## Repository Structure

```text
roadmap-control/
    Trạng thái roadmap, daily log, competency ledger,
    AI usage log, weekly scorecards và recovery records.

learning/
    Bài học, bài tập, starter code, tests và competency practice theo tuần.

firmware/
    stm32/
    esp32/

tests/
    host/
    integration/
    hil/

tools/
    Python scripts và các công cụ hỗ trợ được sử dụng thật.

docs/
    system/
    architecture/
    reports/

evidence/
    Evidence đã chọn lọc: test logs, reports, gate records,
    measurement summaries và reproducibility evidence.

captures/
    Logic-analyzer / protocol captures đã được sanitize.
```

## Governing Documents

Hệ thống V3 được vận hành theo thứ tự ưu tiên:

1. `docs/system/SYSTEM_SPEC_V3.md`
2. `docs/system/EMBEDDED_ROADMAP_V3.1.docx`
3. `docs/system/MASTER_PROMPT_V3.md`
4. `roadmap-control/current-state.md`
5. Repo evidence / logs / scorecards

`CURRENT_STATE` mô tả thực tế hiện tại nhưng không được phép thay đổi luật hoặc roadmap.

## Current Status

Trạng thái hiện tại luôn được đọc từ:

`roadmap-control/current-state.md`

Không suy luận tiến độ chỉ dựa trên ngày tháng hoặc README.

## Evidence Integrity

Evidence trước V3 có thể được giữ làm historical/reference artifact.

Nó không tự động được công nhận là V3 competency evidence.

Các competency chưa được independently revalidated phải được ghi:

`COMPETENCY_UNVERIFIED`

hoặc trạng thái phù hợp theo SYSTEM_SPEC_V3.

## Testing Philosophy

Roadmap sử dụng testing ladder:

- L1 — Host / Unit
- L2 — Peripheral Smoke
- L3 — Integration
- L4 — Fault Injection
- L5 — Soak / Resilience

Mức test bắt buộc phụ thuộc từng milestone.

Không dùng câu "nó chạy được" thay cho test evidence.

## Security

Không commit:

- Wi-Fi password
- API token
- MQTT credential thật
- Private key
- Private certificate material
- Confidential third-party code
- Sensitive recruitment information

Dùng:

`secrets.example`

để mô tả cấu trúc configuration mà không chứa secret thật.

## Development Rule

Commit là engineering snapshot, không phải competency score.

Ví dụ commit message:

```text
feat(ring-buffer): implement bounded push and pop
test(parser): cover malformed frame handling
fix(uart): handle RX overflow condition
docs(week-01): record independent gate result
```

## Scope

Roadmap tập trung vào hai project chính:

1. STM32/FreeRTOS Data Logger
2. STM32–ESP32 Connected Telemetry

Không tự ý thêm technology hoặc project lớn ngoài roadmap nếu chưa có trade-off rõ ràng.

## Final Goal

Đến cuối roadmap, repository phải phản ánh được:

- code tự viết và hiểu được;
- tests tái hiện được;
- hardware measurements;
- debugging/root-cause evidence;
- failure handling;
- project documentation;
- known limitations;
- independent competency gates;
- khả năng defend project trong interview.

Mục tiêu không phải tạo một repository trông hoàn hảo.

Mục tiêu là tạo bằng chứng đáng tin rằng người học có thể làm công việc Embedded/Firmware ở mức internship/entry-level.
