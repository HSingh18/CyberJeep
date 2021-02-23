import React, { useState } from 'react';
import { IonContent, IonHeader, IonPage, IonTitle, IonToolbar, IonInput, IonButton, IonItem, IonCard } from '@ionic/react';
import { useEffect } from 'react'; 
import{Link} from 'react-router-dom'; 
import{loginUser} from '../firebaseConfig';
import ExploreContainer from '../components/ExploreContainer';
import './Login.css';
import { toast } from '../toast';

const Login: React.FC = () => { 
   const [username, setUsername]=useState(''); 
   const [password, setPassword]=useState('');  
   async function login(){ 
      const res= await loginUser(username, password);
      console.log(`${res ? 'Login Success' : 'Login failed'}`); 
      if (!res){ 
          toast('Error Logging in');
      } 
      else{ 
          toast('Successful Login');
      }
   }
   
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar> 
          <IonTitle> Login </IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen class="ion-padding ion-text-center">
        <IonHeader collapse="condense">
          <IonToolbar>
            <IonTitle size="large"></IonTitle>
          </IonToolbar>
        </IonHeader> 
        
        <img src="https://thumbs.dreamstime.com/b/delivery-car-logo-design-inspiration-vector-template-delivery-car-logo-design-vector-template-163969199.jpg"></img>
        <IonItem lines='none' >
        <div id="form">
        <IonInput   
            placeholder="Email"  
            onIonChange={(e:any)=>setUsername(e.target.value)} 
        ></IonInput> 
          </div> 
        </IonItem> 

        <IonItem lines='none'> 
        <div id="form">
        <IonInput  
            type="password"
            placeholder="Password?" 
            onIonChange={(e:any)=>setPassword(e.target.value)} 
        ></IonInput>  
        </div>
        </IonItem>  
        <IonButton color="dark" onClick={login}>Login</IonButton> 
        <p>New to the App?</p><Link to="/Register">Register</Link>
      </IonContent> 
      
    </IonPage>
  );
};

export default Login;
