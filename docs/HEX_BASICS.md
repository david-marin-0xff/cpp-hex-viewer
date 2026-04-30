# Hexadecimal Basics (Learning Notes)

This file exists as a **personal learning reference** for understanding hex editors
and how tools like `cpp-hex-viewer` display data.

---

## 1️⃣ What Is Hexadecimal?

Hexadecimal (base-16) is a number system that uses **16 symbols**:

```
0 1 2 3 4 5 6 7 8 9 A B C D E F
```

Each hex digit represents **4 bits** (half a byte).

- 1 byte = 8 bits
- 1 byte = **2 hex digits**

Example:
```
Byte (binary): 01001000
Hexadecimal:   48
Character:     'H'
```

---

## 2️⃣ Why Hex Is Used

Hex is used because it maps cleanly to bytes and binary data.

- Binary is hard to read
- Decimal hides bit patterns
- Hex shows raw data clearly and compactly

That’s why:
- Hex editors exist
- Network packets are shown in hex
- Files are analyzed in hex

---

## 3️⃣ The Three Main Areas in a Hex View

Most hex viewers show **three columns**:

```
Address (Offset) | Hexadecimal Bytes | ASCII Characters
```

Example:
```
00000000  48 65 6C 6C 6F 20 77 6F 72 6C 64 0D 0A  Hello world..
```

---

## 4️⃣ Address / Offset Area

The **address** (also called offset) tells you:

> How many bytes from the start of the file this data begins.

Example:
```
00000000 → start of file
00000010 → 16 bytes in
00000020 → 32 bytes in
```

Offsets are usually shown in **hexadecimal**.

This is NOT a memory address — it’s a **file position**.

---

## 5️⃣ Hexadecimal Area (Raw Bytes)

This is the **actual file data**, byte by byte.

Example:
```
48 65 6C 6C 6F
```

Each pair:
- `48` → one byte
- `65` → one byte

These bytes mean nothing by themselves — interpretation depends on context.

---

## 6️⃣ ASCII / Character Area

This is a **human-friendly interpretation** of bytes.

- Printable bytes → shown as characters
- Non-printable bytes → shown as `.`
- Null byte → `00`

Example:
```
48 → 'H'
65 → 'e'
6C → 'l'
6C → 'l'
6F → 'o'
```

<img width="916" height="153" alt="image" src="https://github.com/user-attachments/assets/13ea52d6-6940-4b75-8390-1ec1f4f90a8e" />


Binary data (images, executables) mostly show dots here.

---

## 7️⃣ Important Hex Values to Remember

| Hex | Meaning |
|----|--------|
| 00 | Null byte |
| 0A | Line Feed (LF) |
| 0D | Carriage Return (CR) |
| 20 | Space |
| 7F | DEL |
| 41 | 'A' |
| 61 | 'a' |

---

## 8️⃣ Text Files vs Binary Files

### Text files:
- Mostly printable ASCII
- Easy to read in hex
- Patterns visible

### Binary files:
- Random-looking bytes
- Mostly non-printable
- Structure defined by file format

---

## 9️⃣ Endianness (Very Important)

Endianness defines **byte order**.

Example (32-bit value):

```
Value: 0x12345678
```

- Big Endian:
  ```
  12 34 56 78
  ```
- Little Endian (common on x86):
  ```
  78 56 34 12
  ```

Files and systems choose one — mixing them causes bugs.

---

## 🔟 Mental Model When Reading Hex

- Hex shows **truth**
- ASCII is a **hint**
- Address is **position**
- Meaning depends on format

Never assume bytes mean text unless you know the format.

---

## 1️⃣1️⃣ Why Writing a Hex Viewer Helps Learning

Building a hex viewer teaches:
- File I/O
- Binary vs text
- Byte-level thinking
- Memory safety
- Real-world debugging skills

---
.
