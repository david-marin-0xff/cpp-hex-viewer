# How to Build and Use cpp-hex-viewer

This project is a **console-based hex viewer written in C++**.
It compiles into a native Windows executable and can read **any file** as raw hexadecimal bytes.

<img width="1226" height="821" alt="image" src="https://github.com/user-attachments/assets/67b141ef-0c64-4d81-9efd-2820fadd4546" />


---

## 1️⃣ Requirements 

- Visual Studio Build Tools (MSVC)
- Use **x64 Native Tools Command Prompt for VS**
- No Qt, no GUI libraries, no CMake required

---

## 2️⃣ Open the Correct Terminal

⚠️ IMPORTANT  
Always compile using:

**Visual Studio 2026 x64 Native Tools Command Prompt**

PowerShell alone will NOT work for compiling.

---

## 3️⃣ Go to the Project Folder

You must be inside the folder that contains `main.cpp`.

```bat
cd C:\Users\David\cpp-hex-viewer
```

Verify files exist:

```bat
dir
```

You should see:
- `main.cpp`

---

## 4️⃣ Compile the Program

Run this command **from inside the project folder**:

```bat
cl /std:c++20 /EHsc main.cpp
```

This creates:
- `main.exe` → the hex viewer program

You only need to compile again if you change the code.

---

## 5️⃣ How to Use the Program

General syntax:

```bat
main.exe <file_path>
```

The program prints the file contents as hexadecimal bytes.

---

### Examples

Read a binary file:

```bat
main.exe test.bin
```

Read a text file:

```bat
main.exe notes.txt
```

Read an image:

```bat
main.exe image.png
```

Read a file in another folder (full path):

```bat
main.exe C:\Users\David\Downloads\file.bin
```

Read a file using a relative path:

```bat
main.exe ..\Downloads\file.bin
```

---

## 6️⃣ Important Notes

- The program reads **any file** (text or binary)
- The program does NOT modify files (read-only)
- Compilation requires MSVC
- Running `main.exe` works in **any terminal**

- <img width="1151" height="798" alt="image" src="https://github.com/user-attachments/assets/4ae85d6e-2aaa-4165-94dc-29d4bb0c7225" />


---

## 7️⃣ Common Mistakes to Avoid

❌ Running `cl` from PowerShell  
  
✅ Compile once, reuse forever  
✅ Pass any file path you want  

---

## 8️⃣ Mental Model

- `cl main.cpp` → builds the tool  
- `main.exe file` → uses the tool on any file
