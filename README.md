# MP3 Tag Reader and Editor (ID3v2.3)

📄 Project Description

**MP3 Tag Reader and Editor** is a C-based command-line utility designed to interact with **ID3v2.3 metadata tags** in MP3 files. The program allows users to **view** and **edit** embedded song information such as the **title**, **artist**, **album**, **year**, **genre**, and **comment**.

The tool works by reading the MP3 file in binary mode, identifying the specific metadata frames, and either displaying or updating their contents. Edits are performed by creating a temporary MP3 copy with the updated tag, preserving the original structure of the file.

This project demonstrates key concepts in systems programming, such as:

- File I/O with binary data
- Manual endian conversion
- Dynamic memory management
- Modular C programming
- Command-line interface design

---

## ✨ Features

- View ID3v2.3 tags: Title, Artist, Album, Year, Genre, Comment
- Edit individual tag fields in-place
- Manual endian conversion for frame sizes
- Command-line interface with help and usage prompts

---

## 🗂️ File Structure

| File         | Description                                      |
|--------------|--------------------------------------------------|
| `main.c`     | Entry point; parses command-line arguments       |
| `edit.c`     | Modifies ID3v2.3 tag frames in the MP3 file      |
| `view.c`     | Reads and displays tag frames                    |
| `header.h`   | Declarations for shared functions                |

---

## ⚙️ Compilation

Compile the project using GCC:
gcc *.c


🚀 Usage

🔍 View Metadata

./mp3tag -v <filename>.mp3
Displays the following fields (if present):

Title

Artist

Album

Year

Genre

Comment


✏️ Edit Metadata

./mp3tag -e <filename>.mp3 <option> <new_value>

Edit Options:

| Option | Frame | Field   |
| ------ | ----- | ------- |
| `-t`   | TIT2  | Title   |
| `-a`   | TPE1  | Artist  |
| `-A`   | TALB  | Album   |
| `-y`   | TYER  | Year    |
| `-g`   | TCON  | Genre   |
| `-c`   | COMM  | Comment |


Example:

./mp3tag -e song.mp3 -a "Linkin Park"
This updates the artist name in the MP3 file to "Linkin Park".

🆘 Help

./mp3tag
Displays a help menu with available commands and usage instructions.

🧠 Technical Details
ID3v2.3 Tag Format:

10-byte header at the beginning of the MP3 file

Each metadata frame contains:

Frame ID (4 bytes)

Frame size (4 bytes, big endian)

Flags (2–3 bytes)

Content (variable size)

The program scans and processes the first 6 tag frames after the header.

Endianness is handled manually using helper functions.

Tags are read/written using a temporary file (temp.mp3), which replaces the original after editing.

📋 Example

./mp3tag -v sample.mp3

# Output:
Title   :   Numb
Artist  :   Linkin Park
Album   :   Meteora
Year    :   2003
Genre   :   Alternative
Comment :   My favorite track

🚧 Limitations
Only supports reading/editing the first 6 frames after the ID3v2.3 header

Assumes fixed tag frame order

Does not support ID3v1 or ID3v2.4 formats

No error handling for corrupt or malformed MP3 tag structures

📌 Requirements
GCC or compatible C compiler

MP3 files containing ID3v2.3 tags

📄 License
This project is open-source and intended for educational use only.

📝 Summary
This MP3 Tag Reader and Editor offers a practical tool to manipulate ID3v2.3 metadata directly from the terminal. It serves as a strong example of working with binary file formats in C and is well-suited for learning about low-level file handling, metadata parsing, and CLI-based user interaction.

Whether used for automation, learning, or extending into a larger multimedia management system, this tool is a solid base for working with media file metadata in C.