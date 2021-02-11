import { IonContent, IonHeader, IonPage, IonTitle, IonToolbar, IonButton } from '@ionic/react';
import ExploreContainer from '../components/ExploreContainer';
import './Tab3.css';

const Tab3: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle> Send Package </IonTitle> 
        </IonToolbar>
      </IonHeader> 
      <IonToolbar>
            <IonTitle size="large">Sender Destination Selection</IonTitle>
          </IonToolbar>
      <IonContent fullscreen>
        <IonHeader collapse="condense">
          <IonToolbar>
            <IonTitle size="large">Tab 3</IonTitle>
          </IonToolbar>
        </IonHeader>
        <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/f8/Aspect-ratio-16x9.svg/1280px-Aspect-ratio-16x9.svg.png"></img> 
        <IonHeader>
        <IonButton size="large" href="./tab6" class="button-native">Next</IonButton> 
        </IonHeader>
      </IonContent>
    </IonPage>
  );
};

export default Tab3;
