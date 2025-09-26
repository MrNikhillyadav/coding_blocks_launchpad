export function Props(){
    return (
        <div>
            <h1> Props passing</h1>
            <Greeting props={"good evening" }/>
            <Greeting props={"good morning"}/>
            <Greeting props={"bye"}/>
        </div>
    )
}


function Greeting({props}){
    return (
        <div>
            <h1>Hi,{props}</h1>
        </div>
    )
}