# cpp-hex-viewer

A simple modular C++ hex viewer that reads files as raw bytes and prints a structured hex + ASCII dump in the terminal.

<img width="1382" height="557" alt="image" src="https://github.com/user-attachments/assets/559e7c62-c845-4fd9-8d70-a8fbb20ee489" />


## What it does

- Reads any file (binary or text)
- Displays hex bytes
- Shows ASCII representation
- Shows file offsets
- Supports colored terminal output (Windows ANSI enabled)

## Architecture

main()
  ├── CLI (argument parsing)
  ├── HexViewer (hex rendering)
  └── Terminal (ANSI support)

## Build

mkdir build
cd build
cmake ..
cmake --build .

## Run

hexview <file>

Example:

hexview image.jpg

## Current Features (Implemented)

- CLI argument parsing
- Hex dump output
- ASCII column view
- ANSI terminal colors
- File reading in binary mode
- Clean modular structure

## Not Yet Implemented (Roadmap)

- Uppercase hex mode
- Byte search functionality
- Highlight matching bytes
- Jump-to-offset navigation
- UTF-8 awareness improvements
- Interactive terminal mode
- File entropy analysis

## Purpose

This project is for learning:

- C++ systems programming
- Binary file structure
- CLI design
- Terminal rendering
