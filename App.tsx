import { Redirect, Route } from 'react-router-dom';
import {
  IonApp,
  IonIcon,
  IonLabel,
  IonRouterOutlet,
  IonTabBar,
  IonTabButton,
  IonTabs,
} from '@ionic/react';
import { IonReactRouter } from '@ionic/react-router';
import { ellipse, square, triangle, home, bag, send, settings } from 'ionicons/icons';
import Home from './pages/Home';
import RequestPACK from './pages/RequestPACK';
import SendPACK from './pages/SendPACK';
import ACCSettings from './pages/ACCSettings';
import ManualMode from './pages/ManualMode';
import DestinationSelec from './pages/DestinationSelec';
import SenderCheckout from './pages/SenderCheckout';  
import RequesterCheckout from './pages/RequesterCheckout'; 
import Login from './pages/Login'; 
import Register from './pages/Register';

/* Core CSS required for Ionic components to work properly */
import '@ionic/react/css/core.css';

/* Basic CSS for apps built with Ionic */
import '@ionic/react/css/normalize.css';
import '@ionic/react/css/structure.css';
import '@ionic/react/css/typography.css';

/* Optional CSS utils that can be commented out */
import '@ionic/react/css/padding.css';
import '@ionic/react/css/float-elements.css';
import '@ionic/react/css/text-alignment.css';
import '@ionic/react/css/text-transformation.css';
import '@ionic/react/css/flex-utils.css';
import '@ionic/react/css/display.css';

/* Theme variables */
import './theme/variables.css';

const App: React.FC = () => (
  <IonApp>
    <IonReactRouter>
      <IonTabs>
        <IonRouterOutlet>
          <Route exact path="/Home">
            <Home />
          </Route> 
          <Route exact path="/Login">
            <Login />
          </Route> 
          <Route exact path="/Register">
            <Register />
          </Route>
          <Route exact path="/RequestPACK">
            <RequestPACK />
          </Route> 
          <Route exact path="/RequesterCheckout">
            <RequesterCheckout />
          </Route>
          <Route exact path="/SendPACK">
            <SendPACK />
          </Route>
          <Route exact path="/ACCSettings">
            <ACCSettings />
          </Route>
          <Route exact path="/ManualMode">
            <ManualMode />
          </Route>
          <Route exact path="/DestinationSelec">
            <DestinationSelec />
          </Route>
          <Route exact path="/SenderCheckout">
            <SenderCheckout />
          </Route>
          <Route exact path="/">
            <Redirect to="/Home" />
          </Route>
        </IonRouterOutlet>
        <IonTabBar slot="bottom">
          <IonTabButton tab="Home" href="/Home">
            <IonIcon icon={home} />
            <IonLabel>Home</IonLabel>
          </IonTabButton>
          <IonTabButton tab="RequestPACK" href="/RequestPACK">
            <IonIcon icon={bag} />
            <IonLabel>Request</IonLabel>
          </IonTabButton>
          <IonTabButton tab="SendPACK" href="/SendPACK">
            <IonIcon icon={send} />
            <IonLabel>Send</IonLabel>
          </IonTabButton>
          <IonTabButton tab="ACCSettings" href="/ACCSettings">
            {/* want to make this "settings-sharp" */}
            <IonIcon icon={settings} />
            <IonLabel>Settings</IonLabel>
          </IonTabButton>
        </IonTabBar>
      </IonTabs>
    </IonReactRouter>
  </IonApp>
);

export default App;
