import { useState } from 'react';
import './App.css'
import { Light } from './components/Light'
import {ContextApi} from './hooks/ContextApi';


function App() {
  // const [isLightOn,setIsLightOn]  = useState(false);

  return (
    <div>
      {/* <Light  isLightOn={isLightOn} setIsLightOn={setIsLightOn} /> */}
      <ContextApi/>
    </div>
  )
}

export default App
