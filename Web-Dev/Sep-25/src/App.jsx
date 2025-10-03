
import './App.css'
import Greetings from './components/Greetings'

const user1 = {
  name : "Nikhil",
  email : "test@gmail.com"
}
const user2 = {
  name : "Rahul",
  email : "rahul@gmail.com"
}

function App() {
  return (
    <>
      <Greetings props={ user1}/>
      <Greetings props={ user2}/>
    </>
  )
}

export default App
