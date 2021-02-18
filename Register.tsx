import React, { useState } from 'react';
import { IonContent, IonHeader, IonPage, IonTitle, IonToolbar, IonInput, IonButton } from '@ionic/react';
import { useEffect } from 'react'; 
import{Link} from 'react-router-dom';
import ExploreContainer from '../components/ExploreContainer';
import './Register.css';

const Register: React.FC = () => { 
   const [username, setUsername]=useState(''); 
   const [password, setPassword]=useState('');   
   const [cpassword, setCPassword]=useState('');
   function registerUser(){ 
       console.log(username,password, cpassword)
   }
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle> Register </IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen className="ion-padding">
        <IonHeader collapse="condense">
          <IonToolbar>
            <IonTitle size="large"></IonTitle>
          </IonToolbar>
        </IonHeader> 
        <ExploreContainer name="Login" /> 
        
        <IonInput  
            placeholder="Username?"  
            onIonChange={(e:any)=>setUsername(e.target.value)} 
        ></IonInput> 
        <IonInput 
            type="password"
            placeholder="Password?" 
            onIonChange={(e:any)=>setPassword(e.target.value)} 
        ></IonInput>   
         <IonInput 
            type="password" 
            placeholder=" Confirm Password" 
            onIonChange={(e:any)=>setCPassword(e.target.value)} 
        ></IonInput>  
        <IonButton onClick={registerUser}>Register</IonButton> 
        <p>Already have an account?<Link to="/Login">Login</Link></p>
      </IonContent> 
      
    </IonPage>
  );
};

export default Register;
