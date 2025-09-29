import React, { useState } from 'react'

const PropDrilling = () => {
    const [count,setCount] = useState(0)
  return (
    <div>
        <h1>Prop drilling</h1>
        <Counter count={count} setCount={setCount} />
    </div>
  )
}

function Counter({count,setCount}){
    return <div>
        Count :{count}
        <Increment count={count} setCount={setCount} />
        <Decrement count={count} setCount={setCount}/>
    </div>
}

function Increment({setCount}){
    return (
        <div>
            <button onClick={() => setCount((count) => count +1)}>
                increment +
            </button>
        </div>
    )
}

function Decrement({setCount}){
    return (
        <div>
            <button onClick={() => setCount((count) => count -1)}>
                Decrement +
            </button>
        </div>
    )
}

export default PropDrilling