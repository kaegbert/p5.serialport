# p5.serialport 

A [p5.js](http://p5js.org/) library that more or less clones the [Processing Serial Library API](https://processing.org/reference/libraries/serial/index.html).  As JavaScript in a browser can not interact directly with a serial port, it includes a simple Node.js based WebSocket server that performs the actual serial communication.

Currently requires [Node Version 0.12.7](https://nodejs.org/en/blog/release/v0.12.7/)

1. Connect an Arduino or other serial device to your computuer.

2. Install the dependencies server with: ```npm install```

3. Cd to the directory and start the server with: ```node startserver.js```

4. Change the name of the your serial port in sketch.js to match your computer's usb port. 
