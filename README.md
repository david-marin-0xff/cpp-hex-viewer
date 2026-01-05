# cpp-hex-viewer

Console-based **hex viewer** written in **modern C++ (C++20)** for Windows.

This project was created as a **first hands-on C++ project**, focusing on:
- Native compilation
- Binary file handling
- Command-line tools
- Minimal dependencies

---

## 1. How to use (self-reminder)

### Build (Windows / MSVC)

From the **Visual Studio x64 Native Tools Command Prompt**:

cl /std:c++20 /EHsc main.cpp

This generates:

main.exe

---

### Run

Basic usage:

main.exe file.bin

Custom bytes per line:

main.exe -n 32 file.bin

Help:

main.exe --help

---

### Output format

00000000  48 65 6C 6C 6F 20 77 6F 72 6C 64 0D 0A  |Hello world..|

- Left: File offset (hex)
- Middle: Hexadecimal byte values
- Right: ASCII preview (non-printable bytes shown as '.')

---

## 2. Technical specs (how this program works)

### Language & standard

- C++20
- Compiled with MSVC (cl.exe)

---

### Memory management (RAII)

- Uses std::vector<unsigned char> as a byte buffer
- No manual new / delete
- Memory is released automatically when objects go out of scope

Why this matters:
- Prevents memory leaks
- Safer than manual allocation
- Idiomatic modern C++

---

### File handling

- Uses std::ifstream with std::ios::binary
- Reads the file in chunks (default: 16 bytes)
- Does not load entire files into memory
- Works with large files

---

### Binary-safe reading

file.read(reinterpret_cast<char*>(buffer.data()), buffer.size());

- unsigned char is used for raw bytes
- reinterpret_cast is required because streams operate on char*
- file.gcount() returns how many bytes were actually read

---

### Command-line argument parsing

- Uses argc / argv
- Supports flags:
  - -n <bytes>
  - -h, --help
- Manual parsing, no external libraries

---

### Output formatting

- std::hex for hexadecimal output
- std::setw and std::setfill('0') for fixed-width columns
- ANSI escape codes for colored output:
  - Offset: cyan
  - Hex bytes: yellow
  - ASCII: green

---

## 3. Notes to my future self (C++ newbie notes)

### Tooling lessons

- PowerShell alone does NOT configure C++ compilers
- The Visual Studio x64 Native Tools Command Prompt sets:
  - PATH
  - INCLUDE
  - LIB
- cl.exe only works when this environment is loaded

---

### C++ learning takeaways

- C++ is not “hard”, it is explicit
- Headers must be included correctly
- Compiler errors are verbose but precise
- Prefer standard library containers (std::vector, std::string)
- Avoid manual memory management when possible

---

### Design lessons

- Start with console tools, not GUIs
- Small focused programs teach more than large frameworks
- Build incrementally:
  1. Open file
  2. Read bytes
  3. Format output
  4. Add features

---

### Git and workflow notes

- Do not commit .exe files
- Use .gitignore
- Commit early and often
- README files evolve over time

---

## Future ideas

- Pattern search in hex
- Paging (less-style navigation)
- Offset jump
- Cross-platform build
- Unit tests

---

## License

To be decided.
