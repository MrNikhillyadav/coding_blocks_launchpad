import { useRef } from "react"

export function UseRefHook(){
    const nameRef = useRef("");

    function handler(){
        const name = nameRef.current.value;
        console.log('name: ', name);
    }

    return (
        <div>
            <input ref={nameRef} type="text" placeholder="John doe"/>
            <button onClick={handler}>Submit</button>
        </div>
    )
}


