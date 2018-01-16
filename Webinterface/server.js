var app = require('http').createServer(handler);
var io = require('socket.io').listen(app);
var fs = require('fs');
var b = require('bonescript');


var htmlPage = 'index_jquery.html';
var usr_led = 0;
 
b.pinMode('USR0', b.OUTPUT);
b.pinMode('P9_24', b.OUTPUT);
b.pinMode('P9_26', b.OUTPUT);
b.pinMode('P9_42', b.OUTPUT);


 
app.listen(8085);
 
function handler (req, res) {
  fs.readFile(htmlPage,
    function (err, data) {
      if (err) {
        res.writeHead(500);
        return res.end('Error loading file: ' + htmlPage);
      }
      res.writeHead(200);
      res.end(data);
    });
} 

function onConnect(socket)
{
  socket.on('GUIEvent', handleGUIEvent);
}

function printJSON(x) { console.log(JSON.stringify(x)); }

function handleGUIEvent(message)
{
  var data = JSON.parse(message);
  console.log(data.handle + " : " + data.value);
  
  usr_led = !usr_led;
  b.digitalWrite('USR0', usr_led);
  
  switch (data.handle)
  {
    case 'pb_fan':
      b.analogWrite('P9_14', 0.7, 2000, callback);
    break;
    case 'radio-1':
      //manual
      
    break;
    case 'radio-2':
      //automatic
      
    break;
    case 'cb_lamp1':
      b.digitalWrite('P9_24', (data.value == 'true'));
    break;
    case 'cb_lamp2':
      b.digitalWrite('P9_26', (data.value == 'true'));
    break;
    case 'cb_lamp3':
      b.digitalWrite('P9_42', (data.value == 'true'));
    break;
  }
  
  
  
}


function handleAnalogWrite(message)
{
    var data = JSON.parse(message);
    //bb.analogWrite(data.pin, data.value);
    console.log(data.pin + " " + data.value);
}
   
io.sockets.on('connection', onConnect);


// Displaying a console message for user feedback
console.log("Server Running ...");