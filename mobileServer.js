var express = require('express');
var socket = require('socket.io');

// App setup
var app = express();
var server = app.listen(1234, function(){
    console.log('listening for requests on port 1234');
});

// Static files
app.use(express.static('public'));

// Socket setup & pass server
var io = socket(server);
io.on('connection', (socket) => {

    console.log('made socket connection', socket.id);

    socket.on('source', function(data){
        console.log("data recieved from python and sent to react");
        console.log(data.source)
        io.sockets.emit('mobile');
    });

    socket.on('mobile', function(){
        console.log("data recieved on mobile");
    });
});
