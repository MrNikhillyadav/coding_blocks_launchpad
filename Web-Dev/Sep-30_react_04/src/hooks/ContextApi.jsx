import {createContext, useContext, useState} from "react"

const BulbContext = createContext()

function ContextAPIProvider({childern}){
    const [isLightOn, setIsLightOn] = useState(false);
    

    return <BulbContext.Provider value={{isLightOn,setIsLightOn}}>
        {childern}
    </BulbContext.Provider>
}


export default function ContextAPI(){
    return (
        <div>
            <ContextAPIProvider>
                <Light/>
            </ContextAPIProvider>
        </div>
    )
}


function Light(){
    return (
        <>
           <LightBulb  />
           <LightSwitch  />
        </>
    )
}

function LightBulb(){
    const {isLightOn}  = useContext(BulbContext);

    return (
        <div>
            LightBulb status : {isLightOn ? "ON" : "OFF"}
        </div>
    )
}

function LightSwitch(){
    const {isLightOn,setIsLightOn} = useContext(BulbContext);

    function handleToggle(){
        setIsLightOn(!isLightOn)
    }
    return (
        <div>
            <h3>Switch</h3>
            <button onClick={handleToggle}>toggle</button>
        </div>
    )
}