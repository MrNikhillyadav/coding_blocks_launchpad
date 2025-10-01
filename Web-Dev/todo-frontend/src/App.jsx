
import {useEffect, useRef, useState} from 'react'
import './App.css'

function App() {
  const [todos,setTodos] = useState([]);
  console.log('all todos: ', todos);
  const inputRef = useRef("");

  // fetch todo on mount
  useEffect(() => {
    async function getTodo(){
      try {
        const res = await fetch('http://localhost:3000/todo',{
            method : "GET",
            headers : {
              "Content-Type" : "application/json",
              token : "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjY4ZGNmOWQyODBmNTMzNzBjMDJmNmM5MSIsImlhdCI6MTc1OTMxMjM0OX0.tg8fwY5-FgoFK2s1Hd0EpjMlOE1HNY3DjlecpSNoREQ"
            }
        });
  
        const todos = await res.json();
        setTodos(todos.response)
      }
      catch(e){
        console.error("error in fetching todos", e)
      }
    }

    getTodo();
  },[])

// post todo
  async function addTodo(){
    const todo = inputRef.current.value;
    if(!todo.trim()) return ;

    try{
      const res = await fetch('http://localhost:3000/todo',{
        method : "POST",
        body : JSON.stringify({
          title : todo,
          done : false
        }),
        headers : {
          "Content-Type" : "application/json",
          token : "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjY4ZGNmOWQyODBmNTMzNzBjMDJmNmM5MSIsImlhdCI6MTc1OTMxMjM0OX0.tg8fwY5-FgoFK2s1Hd0EpjMlOE1HNY3DjlecpSNoREQ"
        }
      });

      console.log(await res.json())
      inputRef.current.value = "";
    }
    catch(e){
      console.error("error", e)
    }
  }

  // delete todo
  async function deleteTodo(id){
    try{
      const res = await fetch(`http://localhost:3000/todo/${id}`,{
        method : "DELETE",
        headers : {
          "Content-Type" : "application/json",
          token : "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjY4ZGNmOWQyODBmNTMzNzBjMDJmNmM5MSIsImlhdCI6MTc1OTMxMjM0OX0.tg8fwY5-FgoFK2s1Hd0EpjMlOE1HNY3DjlecpSNoREQ"
        }
      });

      console.log(await res.json())
    }
    catch(e){
      console.error("error", e)
    }
  }

  // update todo
  async function EditTodo(id, newTodo){
    try{
      const res = await fetch(`http://localhost:3000/todo/${id}`,{
        method : "PUT",
        headers : {
          "Content-Type" : "application/json",
          token : "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjY4ZGNmOWQyODBmNTMzNzBjMDJmNmM5MSIsImlhdCI6MTc1OTMxMjM0OX0.tg8fwY5-FgoFK2s1Hd0EpjMlOE1HNY3DjlecpSNoREQ"
        },
        body : JSON.stringify({
          title : newTodo,
          done : false
        })
      });

      console.log(await res.json())
    }
    catch(e){
      console.error("error", e)
    }
  }

  return (
    <div>
      <h2> Todo app</h2>
      <div>

        <input ref={inputRef} type="text" placeholder='Go to the gym' />
        <button onClick={addTodo}>Add todo</button>
      </div>
      <div>
        <ul>
          {todos.map((todo) => (
            <li key={todo._id}>
              {todo.title} - {todo.done ? "Done" : "Pending"}

              <button onClick={() => deleteTodo(todo._id)} >delete</button>
              <button
                onClick={
                  async function(){
                    
                    let newTodo = await prompt("edit todo");
                    await EditTodo(todo._id,newTodo)
                  }
                }
              >
                Edit
              </button> 
                
            </li>
          ))}
        </ul>
      </div>
    </div>  
  )
}

export default App
