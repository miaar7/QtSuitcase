

var b = require('bonescript');
var ioctl = require('ioctl');
var fs = require('fs');
//var i2c_b = require('i2c-bus');

//var TMP100_ADDR = 0x48;

var ioctl = require('ioctl');
var fs = require('fs');
var fd = fs.openSync('/dev/i2c-2', 'r+');
var ret = ioctl(fd, 0x0703, 0x48);
var err = fs.writeSync(fd, [0x01, 0x60], 0, 2, 0);




//b.i2cOpen('/dev/i2c-2', 0x48);
//b.i2cOpen(2, 0x48);

  console.log('open file for w/r');
/*
function onFileCloseHandler(err)
{
    if (err)
    {
        console.log(err);
    }
}


function onFileWriteHandler(err, written)
{
    if (err)
    {
        console.log(err);
    }
}

function onFileCloseHandler(err)
{
    if (err)
    {
        console.log(err);
    }
}

/*
var fd = fs.openSync('/dev/i2c-2', 'r+');
var ret = ioctl(fd, 0x0703, 0x48);
var err = fs.writeSync(fd, [0x01, 0x60], 0, 2, 0);
*/


/*

    fs.open('/dev/i2c-2', 'r+', function(err, fd) {
    if (err)
    {
        //throw err;
        console.log(err);
    }
 
 */
 /*
 #define I2C_SLAVE	0x0703	// Use this slave address 
#define I2C_SLAVE_FORCE	0x0706	// Use this slave address, even if it  is already in use by a driver! 
#define I2C_TENBIT	0x0704	// 0 for 7 bit addrs, != 0 for 10 bit 
#define I2C_FUNCS	0x0705	// Get the adapter functionality mask 
#define I2C_RDWR	0x0707	// Combined R/W transfer (one STOP only) 
 */
    /*
 var length = new Buffer(4);
    //var info = new termio();
    var ret = ioctl(fd, 0x0703, TMP100_ADDR);
    
    console.log(ret);
    
    //char config[2] = {0};
    //config[0] = 0x01;
    //config[1] = 0x60;
    //write(this->file, config, 2);
    

    process.env.NODE_DEBUG=fs;


  var bf = new Uint8Array([0x01, 0x60]);
    
    //fs.write(fd, buffer[, offset[, length[, position]]], callback)
    fs.write(fd, bf, 0, 2, null, onFileWriteHandler);
    
    
    
    
    
    
    console.log('fuckface');
    
    //console.log('TCGETA ret: ' + ret);
    //console.log('c_iflag: ' + info.c_iflag);
    //console.log('c_oflag: ' + info.c_oflag);
    //console.log('c_cflag: ' + info.c_cflag);
    //console.log('c_lflag: ' + info.c_lflag);
    //console.log('c_line: ' + info.c_line);
    //console.log('c_cc: ' + info.c_cc.buffer.toString());
    //ret = ioctl(fd, TIOCEXCL);
    //console.log('TIOCEXCL ret: ' + ret);
    fs.close(fd, onFileCloseHandler);
});





  console.log('opened');


  //var i2c_2 = i2c_b.openSync(2);
  //i2c_2.writeByteSync(TMP100_ADDR, CMD_ACCESS_CONFIG, 0x01);
  

 
  //b.writeTextFile('/dev/i2c-2', [0x01, 0x60], {});
  //b.writeTextFile('/dev/i2c-2', [0x00], {});
  

/*
b.readTextFile('/dev/i2c-2', printStatus);
function printStatus(x) {
    console.log('b¨¨og');
}*/