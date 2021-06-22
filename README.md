# SSH_Logger for GNU/Linux


### Summary
An utility for monitoring and logging commands, sent via SSH to/from your Linux PC/server, by strace or ptrace on your choice.

### Motivation
My main idea is to create programm, which will be able to detect and interact with SSH-connections to/from your Linux PC/server. This interaction is to detect new ssh-connections in runtime or scan already opened connections at the program start moment and then hidely and safely attach to their processes and log all commands, sending in these connections. It can be used by Linux systems administrators, who need to detect illegal/doubtful activity by ssh to/from their Linux systems.


### Already implemented features:
 - Automatically scan (every 3 seconds) all SSH-connections (incoming and outgoing) and logging their entire commands into files in ```/var/log/logd/*```(changable by console flags path).
 - Detect at runtime new connections (incoming or outgoing) by SSH and start logging them using **```strace```** for both. This needs to create new processes, which are in output of ```ps```.
 - Detect at runtime new connections (incoming or outgoing) by SSH and start logging them using **```ptrace```** for both. This is hidden way. No ```ps```.
 - Detect closing the connections and stop logging them.
 - Run logger in daemon mode by using flag ```-d```.
 - Opportunity to choose directory to save log files by using flag ```-o```. If this directory doesn't exist, it will be created.


### WIP features:
 - Open choosen by ```-p``` port to listen commands from client (utility in ```tools``` directory) for remote interactions with logger. I think it gives an opportunity to get files with log results remotely and some other features in the future, which can be implemented by ```msgpack``` and ```packio``` libraries =). 


### How to compile and run

```bash
cd SSH_Logger/
mkdir build && cd build
cmake .. && cmake --build .
sudo ./SSH_Logger --help
```

You should start keylloger with ```--help``` flag at the first time to know about available options:

```
Options:
  --help                               produce help message
  -d [ --daemon ]                      daemon mode
  -m [ --mode ] arg (=ptrace)          [strace/ptrace] run ssh logger via 
                                       STRACE or PTRACE mechanism (ptrace by 
                                       default)
  -o [ --output ] arg (=/var/log/logd) path to directory(if it doesn't exist, 
                                       it will be created) for saving logfiles
  -p [ --port ] arg                    port for getting commands to execute 
                                       predefined pool of commands on ssh 
                                       logger side [WIP now]

```


#### Requirements:
 - CMake
 - GCC
 - Boos::[asio, regex, filesystem, programm_options]
