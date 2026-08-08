# CURRENT STATE V3 — EMBEDDED/FIRMWARE ROADMAP

**Document ID:** `CURRENT_STATE_V3`
**Version:** `3.0.0`
**State type:** Operational snapshot — mô tả thực tế hiện tại, không tự tạo luật mới
**Generated at:** `2026-08-09 02:44 +07:00`
**Timezone:** `Asia/Ho_Chi_Minh`
**Owner:** Trần Lê Minh
**Status:** `ACTIVE — PRE-SPRINT-0 REPOSITORY/SYSTEM HARDENING`

---

# 0. NGUỒN SỰ THẬT ĐANG ÁP DỤNG

| Tầng | File / phiên bản | Trạng thái | Vai trò |
|---|---|---|---|
| 1 | `SYSTEM_SPEC_V3.md` — `3.0.0` | `FROZEN BASELINE` | Luật tối cao: PASS, evidence, AI integrity, recovery, state model |
| 2 | `EMBEDDED_ROADMAP_V3.1.docx` — `3.1.0` | `FROZEN ROADMAP BASELINE` | Học gì, khi nào, gate, deadline, project/career milestones |
| 3 | `MASTER_PROMPT_V3.md` — `3.0.0` | `FROZEN CANDIDATE` | Cách ChatGPT vận hành roadmap |
| 4 | `CURRENT_STATE_V3.md` — `3.0.0` | `ACTIVE` | Trạng thái thực tế hiện tại |
| 5 | Repo / logs / tests / captures | `ACTIVE` — Pre-Sprint-0 repo/control-plane evidence | Bằng chứng thực tế |

**Quy tắc:** nếu file này mâu thuẫn với ba tầng phía trên, file này phải được sửa để phản ánh đúng luật; không dùng `CURRENT_STATE` để thay đổi roadmap.

---

# 1. TÓM TẮT TRẠNG THÁI — ĐỌC PHẦN NÀY TRƯỚC

```text
Calendar Position:
PRE-SPRINT-0 — 09/08/2026 — repository/system hardening trước khi chính thức START SPRINT 0.

Execution Position:
PRE-SPRINT-0 / Repository hardening — IN_PROGRESS.
Line-ending policy đã xác minh PASS; UTF-8 BOM cleanup và `dependencies.lock` policy đã sửa local, chưa commit.

Artifact Position:
Pre-Sprint-0 repository/control-plane đã tồn tại và được push.
Đây là setup/operational evidence, KHÔNG phải Sprint 0 technical evidence và KHÔNG phải competency evidence.

Competency Position:
Không có competency V3 nào được xác minh.
Week 1 pre-V3 C evidence = COMPETENCY_UNVERIFIED / RETEST REQUIRED.

Last Artifact PASS:
Không có Sprint 0 technical ARTIFACT_PASS.
Pre-Sprint-0 repository setup có evidence trên `main`; HEAD remote đã quan sát trước state update: `e7ca365`.

Last Competency PASS:
V3: NONE.

Current Outcome:
Freeze repository/system baseline sạch, ít nhiễu, reproducible và đúng bookkeeping trước khi chính thức bắt đầu Sprint 0.

Current Gate:
PRE-SPRINT0-FREEZE — operational setup gate, không phải competency gate.

Schedule Variance:
NOT_COUNTED — Sprint 0 chưa chính thức bắt đầu.

Recovery Status:
NOT_ACTIVE.

Critical Path Risk:
LOW; hardening phải dừng ngay sau freeze để không biến infrastructure polish thành trì hoãn technical work.

Exact Next Action:
Thay `roadmap-control/current-state.md` bằng bản state đã cập nhật này, audit diff, rồi tiếp tục final Pre-Sprint-0 checks trước khi commit/freeze.
```

---

# 2. BỐN VỊ TRÍ TIẾN ĐỘ

## 2.1 Calendar Position — vị trí theo lịch

```text
Date: 2026-08-09
Roadmap position: PRE-SPRINT-0
Phase: Repository/System Hardening
Planned focused load: bounded setup only; không tính là Sprint 0 technical load
Next calendar position: Sprint 0 — chỉ sau explicit START SPRINT 0
```

## 2.2 Execution Position — vị trí đang thực sự làm

```text
PRE-SPRINT-0 / Repository hardening
Status: IN_PROGRESS
Reason: repo/control plane đã bootstrap và push; đang dọn EOL/encoding/git policy/state trước khi freeze.
```

## 2.3 Artifact Position — sản phẩm gần nhất có evidence

```text
V3 artifact position:
NO SPRINT-0 TECHNICAL ARTIFACT YET

Pre-Sprint-0 setup evidence:
- repo `embedded-firmware-journey-v3` tồn tại;
- `main` sync remote tại checkpoint `e7ca365`;
- control files tồn tại;
- `.gitattributes` policy áp `eol=lf`;
- local Git config đã xác minh `core.autocrlf=false`, `core.eol=lf`, `core.safecrlf=false`;
- tracked files kiểm tra không có unintended CRLF;
- 17 tracked files có BOM đã được cleanup local và audit lại không còn BOM;
- `.gitignore` local đã bỏ unconditional `dependencies.lock` ignore;
- các thay đổi hardening local hiện CHƯA commit tại thời điểm snapshot.

Historical/pre-V3 artifact state:
REFERENCE_ONLY until Sprint 0 revalidation.

Do not promote historical artifacts to V3 ARTIFACT_PASS without:
- command/result được chạy lại khi cần;
- hardware/toolchain hiện tại được ghi;
- expected/actual result;
- evidence path;
- AI level/provenance nếu liên quan.
```

## 2.4 Competency Position — năng lực độc lập gần nhất

```text
V3 competency position:
NONE VERIFIED

Pre-V3 Week 1 competency:
COMPETENCY_UNVERIFIED

Reason:
Pre-V3 Week 1 implementation/evidence đã có AI assistance đủ lớn để không còn chứng minh năng lực độc lập.

Required action:
Học/triển khai lại theo V3 và PASS fresh AI-0 competency gate của Week 1.
```

---

# 3. TRẠNG THÁI COMPETENCY

## 3.1 Competencies VERIFIED

```text
NONE under V3.
```

Không nhập một competency vào đây nếu chưa có independent evidence tương ứng.

## 3.2 Competencies UNVERIFIED

### Week 1 — Embedded C foundation

- Pointer và array relationship.
- Pointer arithmetic và bounds.
- Object lifetime / storage duration / linkage.
- `const` placement.
- `static`, `extern`, `volatile`.
- `volatile` không thay atomic/synchronization.
- Struct padding / alignment.
- Endianness.
- Integer promotion và shift safety.
- Undefined behavior cơ bản.
- Memory sections: text/data/bss/stack/heap.
- Safe bit manipulation.
- Fixed-size ring buffer invariants.
- Defensive API/error handling.

**Trạng thái chung:** `COMPETENCY_UNVERIFIED`.

## 3.3 Competencies INVALIDATED / RETEST REQUIRED

```text
Scope:
Các claim competency Week 1 trước V3 dựa chủ yếu trên artifact/test/commit cũ.

Status:
INVALIDATED AS INDEPENDENT COMPETENCY EVIDENCE.

Artifact deletion required?:
NO.

Fresh retest required?:
YES — theo Week 1 V3, AI-0 gate mới.
```

---

# 4. AI INTEGRITY STATUS

## 4.1 Current AI Mode

```text
Current activity:
System/bootstrap documentation.

Permitted:
AI hỗ trợ cấu trúc tài liệu/setup theo luật Sprint 0.

Competency effect:
NONE — file CURRENT_STATE không phải competency evidence.
```

## 4.2 AI-contaminated Evidence

```text
Known affected area:
Pre-V3 Week 1 implementation / tests / commits.

Meaning:
Artifacts có thể giữ để tham khảo lịch sử nhưng không chứng minh independent competency.

Required treatment:
Do not delete merely to hide history.
Do not import as V3 competency PASS.
Relearn/reimplement as scheduled.
Retest using a fresh AI-0 gate.
```

## 4.3 AI Usage Audit Queue

| Item | Trạng thái | Hành động |
|---|---|---|
| Pre-V3 Week 1 code | `CONTAMINATED FOR COMPETENCY` | Giữ reference; không dùng làm independent evidence |
| Pre-V3 Week 1 tests | `ARTIFACT REFERENCE` | Có thể học từ test design nhưng fresh exercises/gate phải độc lập |
| Pre-V3 commit history | `HISTORICAL` | Archive nếu cần; không dùng commit count để claim competency |
| Pre-Sprint-0 repo/system hardening | `IN_PROGRESS` | AI được phép xử lý bookkeeping/operation; không tạo competency PASS |
| Sprint 0 technical setup | `NOT_STARTED` | Chỉ bắt đầu sau explicit START SPRINT 0 |
| Week 1 V3 practice | `PLANNED` | AI-1/AI-2 mặc định; AI-3 sau meaningful attempt |
| Week 1 V3 gate | `PLANNED` | AI-0 |

---

# 5. PRE-SPRINT-0 — CURRENT OPERATION

## 5.1 Mục tiêu duy nhất

> **Freeze repository/system baseline sạch, đúng policy và đúng state trước khi bắt đầu Sprint 0; không dùng setup work để tạo competency PASS giả.**

## 5.2 Pre-Sprint-0 checklist + Sprint 0 future blocks

### Block 1 — Pre-Sprint-0 repo/control plane

- [x] Tạo repo V3 mới.
- [x] Tạo `.gitignore`.
- [x] Tạo `secrets.example`.
- [x] Tạo `roadmap-control/`.
- [x] Đưa `CURRENT_STATE_V3.md` vào repo với tên ổn định `roadmap-control/current-state.md`.
- [x] Tạo `daily-log.md`.
- [x] Tạo `competency-ledger.md`.
- [x] Tạo `ai-usage-log.md`.
- [x] Tạo `weekly-scorecards/`.
- [x] Tạo `recovery/`.
- [x] Ghi source-of-truth versions.
- [x] Initial commit.
- [x] Git push.
- [x] `.gitattributes` + `.editorconfig` được thêm.
- [x] Local Git EOL config được xác minh.
- [x] Không có unintended tracked CRLF.
- [x] UTF-8 BOM cleanup đã PASS local.
- [x] `dependencies.lock` không còn bị ignore global trong repo.
- [ ] Update CURRENT_STATE về đúng PRE-SPRINT-0.
- [ ] Final audit + commit/push hardening.
- [ ] Freeze Pre-Sprint-0.

**Status:** `IN_PROGRESS — near freeze`.

**Known repository checkpoints:**
- `8a1f6f3` — bootstrap V3 roadmap control structure.
- `2435ec4` — complete control files.
- `205b53a` — enforce consistent line endings.
- `e7ca365` — define editor text conventions.

`e918a5f` từng ghi state tiến vào Sprint 0 quá sớm; classification đó được supersede bởi state này.

### Future Sprint 0 / Block 2 — STM32 preflight

- [ ] Nucleo-F446RE được nhận diện đúng.
- [ ] STM32 project baseline build.
- [ ] Flash thành công.
- [ ] Blink hoặc smoke behavior tái hiện.
- [ ] Debug session / breakpoint hoạt động.
- [ ] ST-Link version được ghi.
- [ ] Pin/clock assumptions của baseline được ghi.

**Status:** `NOT_STARTED UNDER V3`.

### Future Sprint 0 / Block 3 — ESP32 preflight

- [ ] ESP-IDF version được pin.
- [ ] `hello_world` hoặc baseline project build.
- [ ] Flash thành công.
- [ ] Monitor log hoạt động.
- [ ] Command build/flash/monitor được lưu.

**Status:** `NOT_STARTED UNDER V3`.

### Future Sprint 0 / Block 4 — Host/tooling/measurement

- [ ] Git hoạt động.
- [ ] Host GCC/C compiler hoạt động.
- [ ] Một host smoke test build/run.
- [ ] UART terminal hoạt động.
- [ ] Logic analyzer/PulseView capture hoạt động nếu hardware sẵn sàng.
- [ ] ARM GCC được kiểm tra.
- [ ] CMake được kiểm tra.
- [ ] Python version được ghi.
- [ ] Toolchain versions được revalidate.

**Status:** `NOT_STARTED UNDER V3`.

### Future Sprint 0 / Block 5 — Inventory/fallback/state close

- [ ] Board/module/cable inventory.
- [ ] 3.3 V / common ground / pinout safety note.
- [ ] MPU6050 availability/status.
- [ ] Optional hardware status.
- [ ] Mock-data/UART fallback documented.
- [ ] Old Week 1 evidence marked competency-unverified.
- [ ] Current state updated with real commands/results.
- [ ] Week 1 Day 1 exact action prepared.

**Status:** `NOT_STARTED`.

---

# 6. FUTURE SPRINT 0 EXIT GATE — NOT ACTIVE YET

**Gate ID:** `SPRINT-0-EXIT`
**Gate type:** Operational/bootstrap — không phải competency gate.

## 6.1 Mandatory exit criteria

- [x] V3 repo tồn tại và push được — Pre-Sprint-0 prerequisite.
- [x] Control files tồn tại — Pre-Sprint-0 prerequisite.
- [ ] STM32 build/flash/debug được revalidated.
- [ ] ESP32 build/flash/monitor được revalidated.
- [ ] Host compiler/test được revalidated.
- [ ] UART terminal hoạt động.
- [ ] Logic analyzer status được ghi (`PASS`, `FAIL`, hoặc `N/A` có lý do).
- [ ] ARM GCC status được ghi.
- [ ] CMake status được ghi.
- [ ] Hardware inventory/safety note hoàn tất.
- [ ] Old competency evidence không bị copy thành PASS.
- [ ] Week 1 Day 1 có thể bắt đầu.

## 6.2 Current gate progress

```text
Completed before Sprint 0:
- V3 repository/control plane created and pushed.
- EOL policy configured and locally verified.
- UTF-8 BOM cleanup performed locally and re-audited.
- `.gitignore` dependency-lock policy corrected locally.
- Old competency evidence remains explicitly unverified.

Sprint 0 technical work:
NOT_STARTED.

Future Sprint 0 missing:
STM32 revalidation;
ESP32 revalidation;
host test;
UART/logic analyzer revalidation;
ARM GCC check;
CMake check;
inventory/fallback;
final Sprint 0 preflight evidence.
```

## 6.3 Exit decision

```text
Current decision:
NOT_ACTIVE

Reason:
Sprint 0 chưa được START. Chỉ đánh giá `SPRINT-0-EXIT` sau explicit START SPRINT 0 và technical preflight.
```

---

# 6.4 PRE-SPRINT-0 HARDENING AUDIT — CURRENT LOCAL EVIDENCE

```text
EOL policy:
PASS

Local Git config:
core.autocrlf=false
core.eol=lf
core.safecrlf=false

Tracked CRLF audit:
PASS — no unintended i/crlf or w/crlf observed.

UTF-8 BOM audit:
17 tracked files initially detected with BOM.
BOM removed locally.
Re-audit result: PASS — no BOM files reported.

Whitespace audit after BOM cleanup / .gitignore edit:
PASS — `git diff --check` produced no output.

ESP-IDF dependency-lock policy:
PASS locally — `dependencies.lock` is no longer globally ignored.

Working tree:
INTENTIONALLY DIRTY — Pre-Sprint-0 hardening changes are not committed yet.

Commit/push:
PENDING final semantic diff audit.
```

**Integrity note:** các PASS ở subsection này là repository hygiene/setup PASS; không phải Sprint 0 technical PASS và không phải competency PASS.

---

# 7. REPOSITORY STATE

## 7.1 V3 repository

```text
Repo URL:
https://github.com/MinhSit/embedded-firmware-journey-v3

Local root:
D:\embedded-firmware-journey-v3

Repository status:
ACTIVE — PRE-SPRINT-0 HARDENING

Default branch:
main

Current branch:
main

Observed remote HEAD before this state update:
e7ca365 — `chore(repo): define editor text conventions`

Current local hardening state:
UNCOMMITTED intentional changes exist for BOM cleanup and `.gitignore` dependency-lock policy; this state replacement will join that same Pre-Sprint-0 hardening change set.

Current release:
N/A
```

## 7.2 Historical pre-V3 repository

```text
Historical repo:
https://github.com/MinhSit/embedded-firmware-journey-2026

Role in V3:
Historical/reference artifact only until specific evidence is revalidated.

Migration policy:
- archive/local copy if needed;
- do not import old competency PASS;
- new V3 repo becomes active source for future evidence;
- public old repo may later be removed by owner after needed audit/reference is preserved.
```

## 7.3 Required V3 skeleton

```text
roadmap-control/
    current-state.md
    daily-log.md
    competency-ledger.md
    ai-usage-log.md
    weekly-scorecards/
    recovery/

learning/
    week-01/
    ...
    week-23/

firmware/
    stm32/
    esp32/

tests/
    host/
    integration/
    hil/

tools/
docs/
evidence/
captures/
```

**Note:** nếu Repo Specification sau này khóa tên chi tiết khác nhưng vẫn giữ cùng semantics, state phải theo spec mới đã được duyệt.

---

# 8. BUILD / TEST STATE

## 8.1 V3 build baseline

```text
Build command:
TBD during Sprint 0.

Latest build result:
NO V3 RESULT YET.

Commit:
N/A.
```

## 8.2 V3 host-test baseline

```text
Test command:
TBD during Sprint 0.

Latest test result:
NO V3 RESULT YET.

Required minimum:
Một host smoke test với strict warning policy phù hợp.
```

## 8.3 Historical results

```text
Historical build/test results:
May exist in pre-V3 repository.

Admissibility:
Reference only until reproduced or explicitly imported as non-competency evidence.
```

---

# 9. HARDWARE STATE

## 9.1 Hardware historically known to have worked

**Pending quick Sprint 0 revalidation:**

- Nucleo-F446RE + ST-Link.
- ESP32-WROOM-32 development board.
- UART/serial path.
- Logic analyzer / PulseView capture workflow.

## 9.2 Hardware requiring Sprint 0 inventory confirmation

- MPU6050 status.
- USB data cables.
- Jumper wires.
- Logic analyzer leads.
- Multimeter availability.
- Optional OLED SSD1306.
- Optional W25Q64 / RTC / DHT21 / CAN transceiver nếu có.

## 9.3 Safety baseline

```text
Logic level:
3.3 V baseline unless exact documentation says otherwise.

Before wiring:
- verify voltage;
- verify common ground;
- verify pin;
- verify alternate function;
- verify direction;
- verify connector;
- verify current/power assumption.

Do not:
Apply 5 V directly to a pin that is not explicitly documented as tolerant.
```

---

# 10. TOOLCHAIN STATE

Các version dưới đây là **historical known state** và phải được revalidated trong Sprint 0 trước khi coi là V3 baseline.

| Tool | Historical value | V3 status |
|---|---|---|
| OS | Windows 10 Pro 22H2 | `PENDING_REVALIDATION` |
| Git | 2.49.0.windows.1 | `PENDING_REVALIDATION` |
| VS Code | 1.131.0 | `PENDING_REVALIDATION` |
| STM32CubeIDE | 2.2.0 | `PENDING_REVALIDATION` |
| STM32CubeMX | 6.18.1 | `PENDING_REVALIDATION` |
| ST-Link firmware | V2J48M35 | `PENDING_REVALIDATION` |
| ESP-IDF | v6.0.2 | `PENDING_REVALIDATION / PIN_REQUIRED` |
| Python | 3.12.0 | `PENDING_REVALIDATION` |
| PulseView | 0.5.0-git-e2fe9df | `PENDING_REVALIDATION` |
| Host GCC | 14.2.0 | `PENDING_REVALIDATION` |
| ARM GCC | Chưa có baseline đáng tin trong V3 | `MUST_CHECK` |
| CMake | Chưa có baseline đáng tin trong V3 | `MUST_CHECK` |

**Rule:** version table được thay bằng kết quả thực tế sau khi chạy lệnh version trong Sprint 0.

---

# 11. OPEN BLOCKERS

## 11.1 P0 blockers

```text
None known at snapshot time.
```

## 11.2 P1 blockers / missing setup evidence

- Pre-Sprint-0 hardening chưa freeze/commit hoàn tất.
- V3 build/test commands chưa được khóa vì Sprint 0 chưa bắt đầu.
- ARM GCC chưa được xác minh.
- CMake chưa được xác minh.
- Hardware/toolchain historical values chưa được revalidated.
- MPU6050 status cần inventory confirmation.

## 11.3 P2

```text
None relevant.
Sprint 0 không cho phép optional polish chen vào.
```

---

# 12. KNOWN BUGS / TECHNICAL DEBT

## 12.1 Technical debt carried from pre-V3

```text
TD-001:
Pre-V3 Week 1 artifact/test/commit không chứng minh independent competency.

Severity:
HIGH for learning integrity, but contained because V3 reset occurs before Week 1.

Disposition:
Do not delete as a cover-up.
Do not use for competency PASS.
Revalidate through fresh V3 learning/gate.
```

## 12.2 System debt

```text
TD-002:
Repo Specification chi tiết chưa được freeze thành file riêng.

Impact:
Low for Sprint 0 if roadmap skeleton semantics are preserved.

Action:
Use roadmap skeleton now; create/freeze detailed repo convention only if still required after bootstrap and without delaying Week 1.
```

---

# 13. CARRY-OVER

```text
Carry-over from old roadmap:
NONE as competency PASS.

Historical setup evidence:
May be reused only as reference to accelerate Sprint 0 revalidation.

Mandatory carry-over:
None — V3 starts clean at Sprint 0.
```

---

# 14. SCHEDULE VARIANCE / RECOVERY / RISK

## 14.1 Schedule variance

```text
Baseline:
Sprint 0 planned for 09/08/2026 after Pre-Sprint-0 freeze.
Week 1 planned start — 10/08/2026.

Current:
Still PRE-SPRINT-0 at snapshot time.

Variance:
NOT_COUNTED until explicit Sprint 0 start.

Reason:
Repository/system hardening is being treated as setup rather than silently claiming Sprint 0 execution.
```

## 14.2 Recovery

```text
Recovery active:
NO.

Recovery trigger currently present:
NO.

Note:
Pre-V3 competency invalidation is already accounted for by the V3 reset and Week 1 revalidation; it is not counted as a new post-V3 recovery event.
```

## 14.3 Critical path risk

```text
Current risk:
LOW.

Escalate to MEDIUM if:
- Pre-Sprint-0 hardening is allowed to expand beyond finite freeze criteria;
- host compiler/test unavailable after Sprint 0 starts;
- STM32 or ESP32 baseline unexpectedly broken;
- essential hardware issue blocks Week 1 preparation.

Escalate to HIGH only if:
- a P0 prerequisite prevents Week 1/Phase 1 work and no fallback exists.
```

---

# 15. WEEKLY SCORECARD

Pre-Sprint-0 không phải technical week và không được chấm như weekly competency gate. Sprint 0 cũng chưa bắt đầu.

```text
Output:        N/A until Sprint 0 close
Understanding: N/A
Testing:       N/A
Documentation: N/A
Health:        N/A
Career:        N/A
```

Sau khi Sprint 0 thực sự diễn ra, chỉ record exit status và preflight evidence.

Week 1 mới bắt đầu scorecard tuần chính thức.

---

# 16. CAREER PIPELINE

```text
Current career phase:
Pre-Week-1 / system bootstrap.

Applications due today:
None mandated by roadmap.

Current V3 tracker:
NOT_CREATED.

CV state under V3:
No project claim should be upgraded based on pre-V3 competency evidence.

Next scheduled meaningful career work:
Follow EMBEDDED_ROADMAP_V3.1 weekly cards beginning after foundation work.
```

---

# 17. HEALTH / LOAD

```text
Pre-Sprint-0 hardening load:
bounded setup only; stop after freeze.

Future Sprint 0 planned load:
6–8 focused hours.

Available focused hours today:
TBD — chưa được ghi tại snapshot.

Known health constraint:
None recorded in current V3 state.

Hard limits:
- no all-nighter;
- no routine >9 focused hours/day;
- after 22:30 prefer log/stop over major changes;
- do not use sleep loss to repay schedule variance.
```

Nếu có thi, bệnh, việc gia đình hoặc giới hạn thực tế, cập nhật ngay field này và dùng load mode phù hợp.

---

# 18. CRITICAL DEADLINES

| Mốc | Ngày | Trạng thái hiện tại |
|---|---:|---|
| Sprint 0 exit | 09/08/2026 | `NOT_STARTED — waits for Pre-Sprint-0 freeze + explicit START` |
| Week 1 start | 10/08/2026 | `PLANNED` |
| Foundation MCU gate | 06/09/2026 | `PLANNED` |
| Data Logger v1.0 | 11/10/2026 | `PLANNED` |
| Telemetry v0.1 | 01/11/2026 | `PLANNED` |
| CAN/schematic/verification gate | 08/11/2026 | `PLANNED` |
| MQTT TLS negative-test gate | 15/11/2026 | `PLANNED` |
| Production + OTA design gate | 29/11/2026 | `PLANNED` |
| HTTPS OTA implementation | 06/12/2026 | `PLANNED` |
| Rollback/resilience + release candidate | 13/12/2026 | `PLANNED` |
| **Project v1.0 hard deadline** | **14/12/2026** | `PROTECTED` |
| Roadmap close | 12/01/2027 | `PROTECTED` |

---

# 19. SCOPE CUTS / SCOPE LOCK

## 19.1 Scope cuts already made by V3 design

```text
No core competency cut.

The reset compresses the calendar by merging/restructuring later release preparation rather than removing:
- Embedded C;
- MCU foundation;
- RTOS/concurrency;
- protocol/parser;
- fault/soak testing;
- Data Logger;
- Telemetry;
- TLS;
- OTA/rollback;
- interview/application pipeline.
```

## 19.2 Locked out before v1.0 unless roadmap amendment explicitly approves

- Linux driver work.
- Yocto.
- FPGA.
- Rust.
- Zephyr.
- TinyML.
- STM32 bootloader/OTA.
- Secure boot/flash encryption extension beyond roadmap scope.
- Third major portfolio project.
- Cosmetic systems work that delays P0 competency.

---

# 20. NEXT GATE

```text
Immediate gate:
SPRINT-0-EXIT

Pass condition:
Repo/control files + toolchain/hardware preflight + old competency claims correctly marked + Week 1 ready.

Next competency gate:
Week 1 Embedded C independent gate.

AI mode for Week 1 gate:
AI-0.
```

---

# 21. WEEK 1 PREVIEW — KHÔNG BẮT ĐẦU TRƯỚC KHI SPRINT 0 ĐÓNG

```text
Week 1 dates:
10/08/2026 – 16/08/2026

Week 1 mission:
Xây Embedded C foundation có thể tự giải thích và tự áp dụng trước khi hardware complexity che lấp lỗ hổng.

Day 1:
Pointer / array model + const placement.

Practice AI policy:
AI-1 theory -> AI-2 hints.
AI-3 only after meaningful attempt.
AI-4/5 contaminates affected competency.

Gate:
Fresh AI-0.
```

Không dùng pre-V3 corrected solution làm starter solution cho fresh gate.

---

# 22. FILES / LINKS ASSISTANT PHẢI KIỂM TRA ĐẦU TIÊN

Theo thứ tự:

```text
1. SYSTEM_SPEC_V3.md
2. EMBEDDED_ROADMAP_V3.1.docx
3. MASTER_PROMPT_V3.md
4. CURRENT_STATE_V3.md
5. roadmap-control/competency-ledger.md
6. roadmap-control/ai-usage-log.md
7. roadmap-control/daily-log.md
8. weekly scorecard gần nhất
9. relevant source/tests/evidence
10. repo commit/release liên quan
```

Historical reference if needed:

```text
https://github.com/MinhSit/embedded-firmware-journey-2026
```

Không dùng old repo để tự động kết luận competency.

---

# 23. EXACT NEXT ACTION

> **Thay `roadmap-control/current-state.md` bằng bản cập nhật này, kiểm tra diff chỉ chứa state correction hợp lệ, rồi hoàn tất final Pre-Sprint-0 audit trước khi commit/freeze.**

**Expected duration:** 5–15 phút.

Không bắt đầu hardware/toolchain preflight và không tự nhảy sang C exercises trước khi Pre-Sprint-0 được freeze.

---

# 24. UPDATE TRIGGERS — KHI NÀO PHẢI SỬA FILE NÀY

Cập nhật `CURRENT_STATE_V3.md` sau:

- `BOOT` khi state thay đổi thực tế;
- `END DAY`;
- `GATE`;
- `RETEST`;
- `WEEKLY REVIEW`;
- `RECOVERY`;
- artifact release/tag;
- build/test baseline change;
- hardware/toolchain change;
- blocker xuất hiện/được đóng;
- AI contamination mới;
- competency PASS/INVALIDATED;
- major application/interview milestone;
- schedule variance thay đổi.

Không update chỉ để làm file “đẹp hơn”.

---

# 25. UPDATE RULES — CHỐNG STATE DRIFT

Khi cập nhật:

1. **Không xóa lịch sử quan trọng bằng cách đổi PASS thành câu mơ hồ.**
2. **Không giữ status cũ nếu evidence mới đã invalidated nó.**
3. **Không tự ghi competency PASS từ artifact/test.**
4. **Không điền field chưa biết bằng phỏng đoán. Dùng `UNKNOWN`, `TBD`, `NOT_VERIFIED`.**
5. **Luôn cập nhật cả bốn position nếu một gate/release làm thay đổi trạng thái.**
6. **AI-4/5 phải làm rõ competency nào cần fresh retest.**
7. **Schedule variance phải ghi số ngày thực tế, không giấu delay.**
8. **Exact Next Action luôn là một bước vật lý 5–15 phút.**
9. **Không copy toàn daily log vào state; chỉ giữ summary cần resume.**
10. **State phải đủ ngắn để assistant mới đọc trước khi làm việc nhưng đủ cụ thể để không hỏi lại lịch sử.**

---

# 26. STATE PATCH TEMPLATE

Dùng sau mỗi event lớn:

```text
STATE PATCH

Generated:
Trigger:

Calendar Position:
Execution Position:
Artifact Position:
Competency Position:

Last Artifact PASS:
Last Competency PASS:

Competencies Newly Verified:
Competencies Newly Unverified/Invalidated:

Current AI Mode:
AI-contaminated Evidence:
Retest Required:

Current Outcome:
Current Gate:
Gate Status:

Repo / Branch / Commit / Release:

Build Command:
Build Result:
Test Command:
Test Result:

New Evidence:

Open Blocker:
Bug / Technical Debt:
Carry-over:

Schedule Variance:
Recovery:
Critical Path Risk:

Health / Load:
Career Pipeline:

Next Gate:
Hard Deadline:

Exact Next Action:
```

Patch chỉ được merge vào state sau khi event thực sự xảy ra.

---

# 27. HANDOFF SUMMARY

Nếu phải chuyển sang account/chat khác ngay tại thời điểm snapshot này:

```text
HANDOFF — CURRENT STATE V3

System Spec:
3.0.0 — FROZEN BASELINE

Roadmap:
EMBEDDED_ROADMAP_V3.1.docx — 3.1.0

Master Prompt:
MASTER_PROMPT_V3.md — 3.0.0

Current State:
CURRENT_STATE_V3.md — 3.0.0

Calendar:
PRE-SPRINT-0 — 09/08/2026

Execution:
Repository/System Hardening — IN_PROGRESS

Artifact:
Pre-Sprint-0 repo/control-plane setup evidence exists; no Sprint 0 technical ARTIFACT_PASS yet.

Competency:
No V3 competency PASS.
Pre-V3 Week 1 C competency = UNVERIFIED / fresh retest required.

Recovery:
Not active.

Critical deadline:
v1.0 — 14/12/2026
Roadmap close — 12/01/2027

Main immediate gap:
Finish/freeze intentional repository hardening; Sprint 0 technical preflight has not started.

Exact next action:
Replace `roadmap-control/current-state.md` with the corrected Pre-Sprint-0 state and audit the diff.
```

---

# 28. STATE INVARIANTS — 10 CÂU KHÔNG ĐƯỢC SAI

1. V3 bắt đầu bootstrap ngày **09/08/2026**.
2. Week 1 chính thức bắt đầu ngày **10/08/2026**.
3. Deadline v1.0 là **14/12/2026**.
4. Roadmap close là **12/01/2027**.
5. Calendar Position không chứng minh work đã làm.
6. ARTIFACT_PASS không chứng minh COMPETENCY_PASS.
7. Pre-V3 Week 1 competency không được import thành PASS.
8. AI-4/5 ở core task yêu cầu fresh independent retest.
9. Ordinary FAIL được xử lý bằng Recovery, không bằng reset roadmap.
10. `Exact Next Action` luôn phải đủ nhỏ để bắt đầu ngay.

---

# 29. CURRENT SNAPSHOT DECISION

```text
Roadmap status:
ACTIVE / ON BASELINE

System status:
V3 documents assembled.
Repository/control-plane bootstrap exists.
Pre-Sprint-0 hardening is IN_PROGRESS and not yet frozen.

Sprint 0:
NOT_STARTED.

Week 1:
NOT_STARTED.

Artifact confidence:
Pre-Sprint-0 repo setup is evidenced.
Hardware/toolchain reproducibility is still unverified under V3 because Sprint 0 has not started.

Competency confidence:
No V3 competency has been independently verified.

AI integrity:
Known pre-V3 Week 1 contamination is explicitly recorded rather than hidden.

Critical path:
Currently protected only if Pre-Sprint-0 hardening is frozen promptly and does not expand into endless infrastructure polish.

Decision:
Finish Pre-Sprint-0 freeze.
Do NOT start Sprint 0 until the owner explicitly starts it.
Do NOT start Week 1 before Sprint 0 mandatory technical preflight is truthfully closed.
```

---

**End of CURRENT_STATE_V3 3.0.0**

**NEXT ACTION recorded in this state:** replace `roadmap-control/current-state.md` with this corrected Pre-Sprint-0 state, audit the diff, then finish the bounded hardening/freeze sequence.