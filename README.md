# cpp-hex-viewer

A simple modular C++ hex viewer that reads files as raw bytes and prints a structured hex + ASCII dump in the terminal.

<img width="1462" height="632" alt="image" src="https://github.com/user-attachments/assets/09fe2650-8b33-4303-9358-91eeb16d72e2" />


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
