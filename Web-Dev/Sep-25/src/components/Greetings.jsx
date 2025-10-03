import './userCard.css'

export default function Greetings({props}){
  return (
    <div className='card'>
      <h1>Hi, {props.name}</h1>
      <h1>email : {props.email}</h1>
    </div>
  )
}