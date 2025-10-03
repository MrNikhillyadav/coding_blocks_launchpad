import './fetchdata.css'

import { useState } from "react"

export function FetchData(){
    const [todos,setTodos] = useState([]);

    async function getTodo(){
        // logic to fetch data from api
        const res = await fetch("https://jsonplaceholder.typicode.com/todos")
        const data = await res.json();
        // console.log('data: ', data);
        setTodos(data)
    }
    
    return <div className='todo-container'>
        <h1>Todos</h1>
        <button onClick={getTodo}>get todos</button>
        
        {/* mapping over the todo items */}
       <div >
             {todos.map((item) => (
            <div className='todo' key={item.id}> 
                {item.id}. 
                <strong>{item.title}</strong>
                <br />
                Compeleted :{item.completed ? "Yes" : "No"}
            </div>
        ))}
       </div>

    </div>
}