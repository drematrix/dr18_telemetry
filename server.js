var express = require('express');
var socket = require('socket.io');

//App setup

var app = express();
var server = app.listen(3000,function(){
    console.log("Listening to requests on port 3000");
});

//static files

app.use(express.static('public'));

//socket setup

var io = socket(server);

io.on('connection', function(socket){
    console.log('made socket connection',socket.id);

    socket.on('imu',function(data){
        //console.log("IMU Data Recieved");
        io.sockets.emit('imu_front', data);
    });

    socket.on('linearPots',function(data){
        //console.log("Linear Pots Data Recieved");
        io.sockets.emit('linearPots_front', data);
    });

    socket.on('camera',function(data){
        //console.log(data);
        io.sockets.emit('camera_front', data);
    });  

});
