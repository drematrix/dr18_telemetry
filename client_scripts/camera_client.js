const cv = require('opencv4nodejs');
var socket = require('socket.io-client')('http://localhost:3000');

//Frames per second
const FPS = 30;

const wCap = new cv.VideoCapture(0);
wCap.set(cv.CAP_PROP_FRAME_WIDTH,300);
wCap.set(cv.CAP_PROP_FRAME_HEIGHT,300);

setInterval(() => {
    
    const frame = wCap.read();
    const image = cv.imencode('.jpg',frame).toString('base64');
    //console.log(image);
    socket.emit('camera',image);

},1000/FPS);

