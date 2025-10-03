import { useEffect,useState } from "react"

export function UseEffectHook(){
    const [count, setCount] = useState(0);

    useEffect(() => {
        //mount logic
        console.log("on mount") // works on mount only

    },[]) // empty depandency array


    useEffect(() => {
        //mount logic
        console.log("on mount")
       setInterval(() => {
            setCount(c => c + 1)
        },1000)

    },[])  // without dependecy array


    useEffect(() => {
        console.log("on mount")
        
       let clock = setInterval(() => {
            setCount(c => c + 1)
        },1000)

        // cleanup logic
        return function(){
            console.log("on unmount")
            clearInterval(clock)
        }

    },[count])  // with dependency array


    return (
        <div>
            <h1>Use Effect hook</h1>
            <p> count : {count} </p>
        </div>
    )
}