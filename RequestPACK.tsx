import { IonContent, IonItem, IonLabel, IonSelect, IonSelectOption, IonButton,IonHeader, IonPage, IonTitle, IonToolbar } from '@ionic/react';
import ExploreContainer from '../components/ExploreContainer';
import './RequestPACK.css';

const RequestPACK: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle> Request Delivery </IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen>
        <IonHeader collapse="condense">
          <IonToolbar>
            <IonTitle size="large">Product Selection</IonTitle>
          </IonToolbar>
        </IonHeader>
        <IonItem>
          <IonLabel>Select Package Size</IonLabel>
          <IonSelect>
            <IonSelectOption value="A4">8.3x11.7 inches</IonSelectOption>
            <IonSelectOption value="A5">5.70 x 8.26  inches</IonSelectOption>
            <IonSelectOption value="Regular">4.33 x 8.26 inches</IonSelectOption>
            <IonSelectOption value="A6">3.54 x 5.51 inches</IonSelectOption> 
            <IonSelectOption value="Pocket">7.48 x 9.84 inches</IonSelectOption> 
            <IonSelectOption value="B5">4.9 x 6.9 inches</IonSelectOption> 
            <IonSelectOption value="B6">3.5 x 4.9 inches</IonSelectOption> 
            <IonSelectOption value="B7 (Passport)">3.5 x 4.9 inches</IonSelectOption>
          </IonSelect>
        </IonItem> 
        <IonButton size="small" href="./Home" class="button-native">Checkout</IonButton>
      </IonContent>
    </IonPage>
  );
};

export default RequestPACK;
