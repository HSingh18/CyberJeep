import { IonContent, IonHeader, IonPage, IonTitle, IonToolbar, IonItem, IonSelect,IonSelectOption, IonLabel, IonButton, IonButtons, IonIcon, IonGrid, IonCol, IonRow } from '@ionic/react'; 
import { personCircle, search, helpCircle, star, create, ellipsisHorizontal, ellipsisVertical, arrowForward, arrowDown, arrowUp, arrowBack } from 'ionicons/icons';
import ExploreContainer from '../components/ExploreContainer';
import './Tab7.css'; 


const Tab7: React.FC = () => { 
  
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle> Manual Mode</IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen>
        <IonHeader collapse="condense">
        </IonHeader> 
        <div id="title">
          <h2>Camera View</h2>
          <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/f8/Aspect-ratio-16x9.svg/1280px-Aspect-ratio-16x9.svg.png"></img>
        </div>
          
        
      <IonGrid>
      <IonRow> 
        <IonCol></IonCol>  
        <IonCol>
        <IonButton> <IonIcon slot="start" icon={arrowUp} /> Forward</IonButton>  
        </IonCol> 
        <IonCol></IonCol>
      </IonRow> 

     <IonRow>  
        <IonCol> 
          <IonButton>
            <IonIcon slot="start" icon={arrowBack} />
            Turn Left
          </IonButton> 
        </IonCol> 
        <IonCol> </IonCol> 
        <IonCol></IonCol>  
        <IonCol>
          <IonButton>
            <IonIcon slot="start" icon={arrowForward} />
            Turn Right 
          </IonButton> 
        </IonCol> 
    </IonRow>  
    <IonRow> 
      <IonCol></IonCol> 
      <IonCol> 
        <IonButton>
          <IonIcon slot="start" icon={arrowDown} />
          <IonLabel>Backward</IonLabel>
        </IonButton> 
      </IonCol> 
      <IonCol></IonCol> 
    </IonRow> 
    </IonGrid>
       
      </IonContent>
    </IonPage>
  );
};

export default Tab7;
