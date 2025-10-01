
import './App.css'
import Navbar from './components/Navbar'
import AboutUs from './pages/AboutUs'
import Home from './pages/Home'
import { BrowserRouter, Routes, Route } from 'react-router-dom';
import Contact from './pages/Contact';
import Blog from './pages/Blog';
import NotFound from './pages/NotFound';

function App() {

  return (
    <BrowserRouter>
     <Navbar/>
     <Routes>
       <Route path='/' element={<Home/>} />
       <Route path='/home' element={<Home/>} />
       <Route path='/contact' element={<Contact/>} />
       <Route path='/about' element={<AboutUs/>} />
       <Route path='/blog' element={<Blog/>} />
       <Route path='*' element={<NotFound/>} />
    </Routes>
    </BrowserRouter>  
  )
}

export default App
