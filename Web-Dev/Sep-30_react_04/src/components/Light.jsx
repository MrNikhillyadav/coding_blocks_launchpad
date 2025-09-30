
export function Light({isLightOn,setIsLightOn}){
    return (
        <>
           <LightBulb isLightOn={isLightOn} />
           <LightSwitch isLightOn={isLightOn} setIsLightOn={setIsLightOn} />
        </>
    )
}


function LightBulb({isLightOn}){
    return (
        <div>
            LightBulb status : {isLightOn ? "ON" : "OFF"}
        </div>
    )
}

function LightSwitch({isLightOn,setIsLightOn}){
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