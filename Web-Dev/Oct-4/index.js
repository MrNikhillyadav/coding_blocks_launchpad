const { WebSocketServer } = require('ws');

const wss = new WebSocketServer({ port: 8080 });

let allSocket = [];

wss.on('connection', (socket) => {
    socket.on("error", () => {
        console.error("error!")
    })
  
    socket.on("open",() => {
        console.log("connected!")
    })

    socket.on('message',(message) => {
       const parsedMsg = JSON.parse(message.toString());
       console.log('parsedMsg: ', parsedMsg);

       // new user joins a room
       if(parsedMsg.type == "join_room"){
            allSocket.push({
                socket,
                room : parsedMsg.payload.room
            })
       }

       // user send a chat message
       if(parsedMsg.type == "chat"){
            // find current user room
            const currentUserSocket = allSocket.filter((x) => x.socket == socket);

            if(!currentUserSocket) return;
    
            const currentRoomUsers = allSocket.filter((x) => x.room == currentUserSocket[0].room);
    
            // filter out other sockets in same room and send message
            for(let i = 0; i < currentRoomUsers.length; i++){
                currentRoomUsers[i].socket.send(JSON.stringify(parsedMsg.payload.message));
            }
        }

    })

    socket.on("close",() => {
        console.log("connection closed!")
        allSocket.filter((x) => x.socket == socket)
        allSocket = allSocket.filter(x => x.socket !== socket);
    })
});