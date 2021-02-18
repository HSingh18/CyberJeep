
import  firebase from 'firebase/app' 
import "firebase/auth" 
const config={ 

    apiKey: "AIzaSyAVaLERLGq7jNi11aPcLAWyfHLtyncX_VU",
    authDomain: "mobileapp-cfa76.firebaseapp.com",
    projectId: "mobileapp-cfa76",
    storageBucket: "mobileapp-cfa76.appspot.com",
    messagingSenderId: "145561188114",
    appId: "1:145561188114:web:64e29f5fc574101719a5cb"
    
};
firebase.initializeApp(config); 
export async function loginUser(username:string, password: string) {    
        const email=`${username}@gmail.com`; 
        try{
                const res=await firebase.auth().signInWithEmailAndPassword(email, password); 
                console.log(res); 
                return true
        }
        catch(error){ 
                console.log(error); 
                return false
        }
} 
