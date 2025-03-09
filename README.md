# Chat - Simple TCP Messenger

A basic client-server chat application using TCP sockets in C.

## Prerequisites

* GCC
* Make (optional, if using ```make``` for compilation)

## 📥 Installation

Clone the repository:  
```bash
git clone https://github.com/IANDYI/Chat.git
cd Chat
```

## ⚙️ Compilation

**Using GCC (Manual Compilation)**

Compile both the server and client:

```bash
gcc -Wall -Wextra -O2 -o server server.c
gcc -Wall -Wextra -O2 -o client client.c
```

**Using Make (Recommended)**

Use the included Makefile:

```bash
make
```

To clean up compiled files:

```bash
make clean
```
## 🚀 Running the Application

**Start the Server**

Run the server in one terminal:

```bash
./server
```

**Start the Client**

Run the client in another terminal:

```bash
./client
```

## 📜 License

MIT License. See LICENSE for details.
