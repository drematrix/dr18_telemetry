var socket = require('socket.io-client')('http://localhost:1234');

export default class App extends React.Component {

  constructor(){
    super()
    
    console.log("Hey");
    var socket = require('socket.io-client')('http://localhost:1234');
    //socket.connect();
    socket.on('connect', function(){
      console.log('connected')
    });
    socket.on('mobile',() =>{
      console.log("recieving"),
      this.setState({speed: 40})
      //this.render()
      io.sockets.emit('mobile');
    });

    this.spinValue = new Animated.Value(0)
  }


}

//AppRegistry.registerHeadlessTask('Rotatejs', () => require('Rotatejs'));
