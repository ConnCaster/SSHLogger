# SSH_Logger for GNU/Linux


### Summary
An utility for monitoring and logging commands, sent via SSH to/from your Linux PC/server, by strace or ptrace on your choice.

### Motivation
My main idea is to create programm, which will be able to detect and interact with SSH-connections to/from your Linux PC/server. This interaction is to detect new ssh-connections in runtime or scan already opened connections at the program start moment and then hidely and safely attach to their processes and log all commands, sending in these connections. It can be used by Linux systems administrators, who need to detect illegal/doubtful activity by ssh to/from their systems.


### Already implemented features:
 - Automatically scan (every 3 seconds) all SSH-connections (incoming and outgoing) and logging their entire commands into ```/var/log/logd/*```.
 - Detect new connections (incoming or outgoing) by SSH and start logging them using **```strace```** for both.
 - Detect new connections (incoming or outgoing) by SSH and start logging them using **```ptrace```** for both.
 - Detect closing the connections and stop logging them.
 - Run logger in daemon mode by using flag ```-d```.
 - Opportunity to choose directory to save log files by using flag ```-o```. If this directory doesn't exist, it will be created.


### How to compile and run

```bash
cd SSH_keylloger/
mkdir build && cd build
cmake .. && cmake --build .
sudo ./keylogger --help
```

You should start keylloger with ```--help``` flag at the first time to know about available options:

```
Options:
  --help                               produce help message
  -d [ --daemon ]                      daemonize mode
  -m [ --mode ] arg (=ptrace)          [strace/ptrace] run ssh keylogger via 
                                       STRACE or PTRACE mechanism (ptrace by 
                                       default)
  -o [ --output ] arg (=/var/log/logd) path to directory(if it doesn't exist, 
                                       it will be created) for saving logfiles
```


#### Requirements:
 - CMake
 - GCC
 - Boost (regex, filesystem)
