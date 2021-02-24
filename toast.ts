export function toast(message:string, duration=2000) {
    const toast = document.createElement('ion-toast');
    toast.message = message;
    toast.duration = duration;
  
    document.body.appendChild(toast);
    return toast.present(); 
} 

export  function dis(message:string) { 
    let a =document.createElement('a'); 
    a.target='blank'; 
    a.href='./home';  
    if (window.confirm('Ok to Confirm, Cancel to Stay here'))
    {
    a.click();
    };

} 

export function gohome(){  
    let a =document.createElement('a');  
    a.href='./home';  
    a.click();
} 