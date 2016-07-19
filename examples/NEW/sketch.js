var serial;          // variable to hold an instance of the serialport library
var portName = '/dev/cu.usbmodemFA131'; // fill in your serial port name here
var a = new Audio('audio/e.mp3');
var b = new Audio('audio/a.mp3');


function setup() {
 rectMode(CENTER);
 createCanvas(800, 800);          // make canvas
 smooth();                        // antialias drawing lines
 serial = new p5.SerialPort();    // make a new instance of the serialport library
 serial.on('list', printList);    // set a callback function for the serialport list event
 serial.on('connected', serverConnected); // callback for connecting to the server
 serial.on('open', portOpen);     // callback for the port opening
 serial.on('data', serialEvent);  // callback for when new data arrives
 serial.on('error', serialError); // callback for errors
 serial.on('close', portClose);   // callback for the port closing

 serial.list();                   // list the serial ports
 serial.open(portName);           // open a serial port
}

// var one;
var photo1, photo2, photo3, photo4, photo5, photo6;      // location of the circle
var circleColor = 255; // color of the circle
function draw() {
  println(photo5);
 background(0);               // black background
 fill(circleColor);           // fill depends on the button
 // ellipse(locH, locV, 50, 50); // draw the circle

fill(0,100,200);
rect(200,250,70,70); //photocell 1
fill(255);
text("photocell 1", 207,330,70,70); //photocell 1

fill(0,100,200);
rect(400,250,70,70); //photocell 2
fill(255);
text("photocell 2", 407,330,70,70); //photocell 2

fill(0,100,200);
rect(600,250,70,70); //photocell 3
fill(255);
text("photocell 3", 607,330,70,70); //photocell 3

fill(0,100,200);
rect(200,550,70,70); //photocell 4
fill(255);
text("photocell 4", 207,630,70,70); //photocell 4

fill(0,100,200);
rect(400,550,70,70); //photocell 5
fill(255);
text("photocell 5", 407,630,70,70); //photocell 5

fill(0,100,200);
rect(600,550,70,70); //photocell 6
fill(255);
text("photocell 6", 607,630,70,70); //photocell 6


 if (photo1 > 300) {
    noStroke();
    fill(255);
    rect(200,250,70,70); //photocell 1
    text("has broken threshold", 207,350,70,70); //photocell 1
    a.play();
  }

  if (photo2 > 320) {
     noStroke();
     fill(255);
     rect(400,250,70,70); //photocell 2
     text("has broken threshold", 407,350,70,70); //photocell 2
     b.play();
   }

   if (photo3 > 250) {
      noStroke();
      fill(255);
      rect(600,250,70,70); //photocell 3
      text("has broken threshold", 607,350,70,70); //photocell 3
      // c.play();
    }

    if (photo4 > 270) {
       noStroke();
       fill(255);
       rect(200,550,70,70); //photocell 4
       text("has broken threshold", 207,650,70,70); //photocell 4
      //  d.play();
     }

     if (photo5 > 240) {
        noStroke();
        fill(255);
        rect(400,550,70,70); //photocell 5
        text("has broken threshold", 407,650,70,70); //photocell 5
       //  d.play();
      }

      if (photo6 > 270) {
         noStroke();
         fill(255);
         rect(600,550,70,70); //photocell 6
         text("has broken threshold", 607,650,70,70); //photocell 6
        //  d.play();
       }


}

// get the list of ports:
function printList(portList) {
 // portList is an array of serial port names
 for (var i = 0; i < portList.length; i++) {
 // Display the list the console:
 println(i + " " + portList[i]);
 }
}

function serverConnected() {
 println('connected to server.');
}

function portOpen() {
 println('the serial port opened.')
}

function serialError(err) {
 println('Something went wrong with the serial port. ' + err);
}

function portClose() {
 println('The serial port closed.');
}

function serialEvent() {
  // read a string from the serial port
  // until you get carriage return and newline:
  var inString = serial.readStringUntil('\r\n');
  //check to see that there's actually a string there:
  if (inString.length > 0) {
    if (inString !== 'hello') {           // if you get hello, ignore it
      var sensors = split(inString, ','); // split the string on the commas
      if (sensors.length > 6) { // if there are three elements
        println(sensors);
        photo1 = map(sensors[0], 70, 100, 0, -150);
        photo2 = map(sensors[1], 70, 100, 0, -150);
        photo3 = map(sensors[2], 70, 100, 0, -150);
        photo4 = map(sensors[3], 70, 100, 0, -150);
        photo5 = map(sensors[4], 70, 100, 0, -150);
        photo6 = map(sensors[5], 70, 100, 0, -150);

        fill(255);
        circleColor = 255 - (sensors[2] * 100);      // element 2 is the button
      }
    }
    serial.write('x'); // send a byte requesting more serial data
  }
}

function keyPressed() {
  if (key == 'A') {
    a.play();
    // background(200, 100, 0);

  }
}

function gotData() {
  var currentString = serial.readLine();  // read the incoming data
  trim(currentString);                    // trim off trailing whitespace
  if (!currentString) return;             // if the incoming string is empty, do no more
  console.log(currentString);
}
