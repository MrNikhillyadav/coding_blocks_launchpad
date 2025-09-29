import { useState } from "react"

export function UseStateHook(){
    const [count,setCount] = useState(0);

    function handleIncrement(){
        setCount( c => c +1);
    }

    function handleDecrement(){
        setCount( c => c -1);
    }

    return <div>

        <h1>Count : {count} </h1>

        <button onClick={handleIncrement}>Increment +</button>
        <button onClick={handleDecrement}>Decrement -</button>
    </div>
}