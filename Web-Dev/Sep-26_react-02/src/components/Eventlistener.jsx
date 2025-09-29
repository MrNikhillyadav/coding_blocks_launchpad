
function onClickHandler(){
    console.log("btn is clicked!")
}

function onMouseEnterHandler(){
    console.log("hovered me!")
}

export function Eventlistener(){
return (
    <div>
        <h1>EventListener component</h1>

        <button onClick={onClickHandler}>click</button>
        
        <button onMouseEnter={onMouseEnterHandler}>hover me</button>
    </div>
)}