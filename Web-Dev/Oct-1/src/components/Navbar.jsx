import React from 'react'
import {Link} from 'react-router-dom'
import './navbar.css'

const Navbar = () => {
  return (
    <div className='Navbar'>
        <Link to={'/home'}> Home</Link> 
        <Link to={'/about'}> About</Link> 
        <Link to={'/contact'}> Contact</Link> 
        <Link to={'/blog'}> Blog</Link> 
        
    </div>
  )
}

export default Navbar