# Command Line Parser – Table Pattern

## 1. Overview

Project này implement một **Command Line Interface (CLI)** đơn giản trong C theo **Table Pattern** , thường dùng trong hệ thống Embedded để xử lý lệnh từ UART/terminal.

### a. Table Pattern là gì?

**Table Pattern** là cách thiết kế trong đó:

- Các command được lưu trong một **bảng (table)**
- Mỗi command sẽ map tới một **function handler**

#### Structure

```c
typedef struct
{
    const int8_t *cmd;
    pf_cmd_func func;
    const int8_t *info;
} cmd_line_t;
```

Ví dụ:

```c
cmd_line_t cmd_table[] = {
    {(int8_t *)"help", cmd_help, (int8_t *)"Show help"},
    {(int8_t *)"led", cmd_led, (int8_t *)"Control LED"},
    {0, 0, 0}};
```

#### Cách hoạt động

1. Nhận input (ví dụ: `"led on"`)
2. Tách command (`"led"`)
3. So sánh với table
4. Gọi handler tương ứng

Ưu điểm:

- Dễ mở rộng (chỉ cần thêm vào table)
- Code clean, không cần if-else dài dòng
- Rất phổ biến trong firmware

### b. Cách kiểm thử

Project sử dụng **Unit Test** để kiểm tra logic parser.

#### Các test case

| Test case                      | Cách thực hiện | Kết quả thực tế |
| ------------------------------ | -------------- | --------------- |
| Command hợp lệ (`help`)        | B1             | C1              |
| Command có argument (`led on`) | B2             | C2              |
| Command không tồn tại (`abc`)  | B3             | C3              |
| Command quá dài                | B1             | C1              |
| Table NULL                     | B2             | C2              |

#### Build & Run

- **Cách 1: Dùng GCC (đơn giản)**

  ```bash
  gcc cmd_line.c test_cmd_line.c ../lib/unity.c -o test
  test
  ```
- **Cách 2: Chạy demo main (thủ công)**

  ```bash
  gcc cmd_line.c main.c -o main
  main
  ```

### c. Demo input/output

#### Input

```text
help
led on
abc
```

#### Output

```text
Simple CLI (type 'exit' to quit)
> help
Available commands: help, led

> led on
LED command with arg: led on

> abc
Command not found

> exit
```

## 2. Unity Test Framework là gì?

Unity là **standard trong embedded testing**:

- Viết bằng C
- Nhẹ (rất hợp embedded)
- Không cần OS
- Không cần dynamic memory

Dùng trong:

- Automotive (AUTOSAR)
- IoT firmware
- RTOS projects

Tải 2 file:

- `unity.c`
- `unity.h`

👉 từ GitHub: [https://github.com/ThrowTheSwitch/Unity](https://github.com/ThrowTheSwitch/Unity)
