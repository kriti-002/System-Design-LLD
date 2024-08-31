# File System Simulation

## Overview

This C++ program simulates a simple file system using object-oriented programming principles. It allows users to create and manage files and directories. Users can add files and directories to the root directory (`home`), display the contents of the root directory, and navigate through the hierarchical structure.

## Features

- **Add File**: Add a file to the root directory or create a new directory and add the file to it.
- **Add Directory**: Create a new directory and add it to the root directory.
- **Show**: Display the contents of the root directory, including files and directories.

## Class Structure

- **FileSystem**: Abstract base class with a pure virtual method `ls()` that needs to be implemented by derived classes.
- **File**: Inherits from `FileSystem`. Represents a file with a name.
- **Directory**: Inherits from `FileSystem`. Represents a directory that can contain other files or directories.

## Code Explanation

1. **FileSystem Class**:
   - Abstract base class defining the interface for files and directories.
   - Contains a pure virtual method `ls()` to list contents.

2. **File Class**:
   - Represents a file with a name.
   - Implements the `ls()` method to display the file's name.

3. **Directory Class**:
   - Represents a directory that can contain files and other directories.
   - Contains a vector `listOfFile` to store pointers to `FileSystem` objects.
   - Implements the `ls()` method to display the directory's name and recursively list its contents.

4. **Main Function**:
   - Provides a simple text-based interface for the user to interact with the file system.
   - Options include adding files and directories or displaying the contents of the root directory.

## Usage

1. **Add File**:
   - Enter the file name when prompted.
   - Choose whether to add the file to an existing directory or create a new directory for it.

2. **Add Directory**:
   - Enter the name of the new directory when prompted.

3. **Show**:
   - Displays the contents of the root directory, including any nested directories and files.

## Notes

- The current implementation adds directories and files directly to the `home` directory. If more complex directory navigation is required, additional functionality should be implemented.
- Memory management is handled by manual allocation (`new`) and does not include advanced error checking.

## Future Scope
- For a directory already present, create a system to add a file for it.