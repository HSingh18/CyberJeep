import { IonContent, IonButton,IonHeader, IonPage, IonTitle, IonToolbar, IonItem, IonSelect, IonSelectOption, IonLabel } from '@ionic/react';
import ExploreContainer from '../components/ExploreContainer';
import './SendPACK.css';

const SendPACK: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle> Send Package </IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen>
        <IonHeader collapse="condense">
          <IonToolbar>
            <IonTitle size="large">Product Selection</IonTitle>
          </IonToolbar>
        </IonHeader> 
        <IonItem>
          <IonLabel>Select Package Set Destination</IonLabel>
          <IonSelect>
            <IonSelectOption value="dest1">Location 1</IonSelectOption>
            <IonSelectOption value="dest2">Location 2</IonSelectOption>
            <IonSelectOption value="dest3">Location 3</IonSelectOption>
            <IonSelectOption value="dest4">Location 4</IonSelectOption> 
          </IonSelect> 
          </IonItem> 
        <IonButton size="small" href="./SenderCheckout" class="button-native">Next</IonButton>
      </IonContent>
    </IonPage>
  );
};

export default SendPACK;
