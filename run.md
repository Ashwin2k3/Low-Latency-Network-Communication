Here's a Bash script that automates the process of building and running the low-latency network communication module as described. This script assumes you have CMake and Boost.Asio installed on your system.


### **Script Details**

- **`usage()`**: Displays usage information for the script.
- **`build()`**: Creates a `build` directory, runs CMake to generate build files, and compiles the project.
- **`run()`**: Executes the built executable. It checks if the executable exists before trying to run it.
- **`test()`**: Builds and runs unit tests located in the `tests` directory. Assumes tests are set up with CMake.
- **`clean()`**: Removes build artifacts from the `build` directory and cleans up the `tests` build directory.

### **How to Use the Script**

1. **Make the Script Executable**:
   ```bash
   chmod +x script_name.sh
   ```

2. **Build the Project**:
   ```bash
   ./script_name.sh build
   ```

3. **Run the Application**:
   ```bash
   ./script_name.sh run
   ```

4. **Run Unit Tests**:
   ```bash
   ./script_name.sh test
   ```

5. **Clean Up Build Files**:
   ```bash
   ./script_name.sh clean
   ```

Replace `script_name.sh` with the name of your script file. This script simplifies the process of building, running, and testing your project, making it easier to manage your development workflow.
