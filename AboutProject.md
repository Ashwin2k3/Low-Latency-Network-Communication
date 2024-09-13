### **Program Overview**

This C++ project implements a low-latency network communication module using Boost.Asio. It creates a TCP server that:

1. **Listens for incoming connections** on a specific host (127.0.0.1) and port (12345).
2. **Accepts client connections** and handles them asynchronously.
3. **Reads data** from the client, processes the data (converts it to uppercase), and **sends it back** to the client (echoes the data).
4. Handles multiple clients simultaneously, thanks to asynchronous I/O and Boost.Asio.

### **Demonstration**

#### **1. Run the Server**

After building the project, you can start the server by executing the `NetworkCommunication` binary.

```bash
./NetworkCommunication
```

Once the server is running, it will listen on `localhost:12345` for incoming client connections.

#### **2. Connect a Client to the Server**

To test the server, open another terminal and use a tool like `telnet` or `netcat` to connect to the server.

**Using `telnet`:**
```bash
telnet localhost 12345
```

or

**Using `netcat` (`nc`):**
```bash
nc localhost 12345
```

Once connected, you can type a message, and the server will respond by echoing the message back in uppercase.

#### **3. Example Interaction**

**Client:**

```bash
telnet localhost 12345
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
hello server
HELLO SERVER
```

Here’s what happens during this interaction:

- The client sends the message `"hello server"` to the server.
- The server receives the message, processes it by converting it to uppercase, and then sends the processed message (`"HELLO SERVER"`) back to the client.

#### **4. Multiple Clients**

You can open multiple terminals and connect additional clients. Each client will have its data processed independently by the server, as the server uses asynchronous I/O for low-latency handling of multiple connections.

For example, if you connect another client:

**Client 2:**

```bash
telnet localhost 12345
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
test message
TEST MESSAGE
```

The server handles both clients independently.

#### **Server Output**

In the server terminal, you’ll see messages indicating the connections and received data:

```bash
Client connected!
Received: hello server
Received: test message
```

### **Program Flow**

1. **Server Initialization**:
   - The server starts by binding to `localhost:12345` (specified in `config.json`).
   
2. **Client Connection**:
   - The server waits for clients to connect. Once a client connects, it starts reading data asynchronously.
   
3. **Data Processing**:
   - Upon receiving data from the client, the server processes it (in this case, converts it to uppercase).
   
4. **Data Echo**:
   - The server sends the processed data back to the client.

5. **Multiple Clients**:
   - The server is capable of handling multiple clients at once, echoing data to each client separately.

### **Use Cases**

This project serves as a foundation for building real-time, low-latency network communication systems. Potential use cases include:

- **Financial Trading Systems**: Low-latency systems are essential for High-Frequency Trading (HFT), where trades are made in milliseconds.
- **Game Servers**: Where real-time data exchange with minimal delay is required between players and the game server.
- **Chat Applications**: You can build chat applications that allow users to communicate in real time.
- **IoT Device Communication**: For receiving and sending data between devices in real-time with low latency.

### **Testing**

To test the project:

1. **Build the project** with CMake.
2. **Run the server** using `./NetworkCommunication`.
3. **Connect clients** using tools like `telnet` or `netcat` to send messages and observe how the server processes and responds.

Let me know if you'd like further enhancements or changes!
