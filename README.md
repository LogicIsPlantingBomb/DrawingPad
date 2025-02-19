# Drawing Pad Project.

This project is a simple drawing pad implemented using SDL2. Users can draw on the screen using the mouse and reset the canvas by pressing the **'R'** key.

## Features
- Interactive drawing using the mouse
- Grid-based structure for better alignment
- Reset functionality using the **'R'** key
- Simple SDL2-based implementation
## Screenshot
![DrawingPad](https://github.com/user-attachments/assets/32d6c176-56c7-4206-9fb5-170af3bb3f5c)

## Prerequisites
Ensure you have the following installed on your system:
- **SDL2**
- **GCC** or any C compiler
- **Make** (optional, for build automation)

## Installation and Compilation
1. Clone the repository:
   ```sh
   git clone git@github.com:LogicIsPlantingBomb/DrawingPad.git
   cd DrawingPad
   ```
2. Install SDL2 (if not already installed):
   ```sh
   sudo pacman -S sdl2   # For Manjaro/Arch-based systems
   ```
3. Compile the program:
   ```sh
   gcc -o drawing_pad drawing_pad.c -lSDL2
   gcc DrawingPad.c -o DrawingPad $(pkg-config --cflags sdl2) $(pkg-config --libs sdl2)

   ```
4. Run the program:
   ```sh
   ./drawing_pad
   ```

## Usage
- Click and drag the mouse to draw on the canvas.
- Press **'R'** to clear the canvas and reset the grid.
- Close the window to exit the program.



## Future Improvements
- Add color selection for drawing
- Implement an undo feature
- Save drawings as images
- Improve rendering efficiency

## License
This project is open-source. Feel free to modify and distribute it as needed.

## Contributions
Contributions are welcome! Feel free to open an issue or submit a pull request to enhance the project.

## Author
**Dhruv Bhardwaj**

