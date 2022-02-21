import * as React from 'react';
import { DevSettings, View, Text, StatusBar } from 'react-native';
import AsyncStorage from '@react-native-community/async-storage';
import HooksExample from './HooksExample';
import SafeAreaViewExample from './SafeAreaViewExample';
// import ReactNavigationExample from './ReactNavigationExample';
import ReactNavigationNativeStackExample from './ReactNavigationNativeStackExample';

const STORAGE_KEY = 'rnsac-current-example-v2';

type Example = 'safe-area-view' | 'hooks' | 'react-navigation' | 'native-stack';

export default function App() {
  const [currentExample, setCurrentExample] = React.useState<Example | null>(
    null,
  );
  const [statusBarHidden, setStatusBarHidden] = React.useState(false);

  React.useEffect(() => {
    async function loadCurrentExample() {
      const example = await AsyncStorage.getItem(STORAGE_KEY);
      setCurrentExample((example as Example | null) ?? null);
    }
    loadCurrentExample();
  }, []);

  React.useEffect(() => {
    async function saveCurrentExample() {
      if (currentExample != null) {
        await AsyncStorage.setItem(STORAGE_KEY, currentExample);
      }
    }
    saveCurrentExample();
  }, [currentExample]);

  React.useEffect(() => {
    DevSettings.addMenuItem('Toggle Status Bar', () => {
      setStatusBarHidden((s) => !s);
    });
    DevSettings.addMenuItem('Show SafeAreaView Example', () => {
      setCurrentExample('safe-area-view');
    });
    DevSettings.addMenuItem('Show Hooks Example', () => {
      setCurrentExample('hooks');
    });
    DevSettings.addMenuItem('Show React Navigation Example', () => {
      setCurrentExample('react-navigation');
    });
    DevSettings.addMenuItem('Show Native Stack Example', () => {
      setCurrentExample('native-stack');
    });
  }, []);

  let content: React.ReactElement<unknown>;
  switch (currentExample) {
    case 'safe-area-view':
      content = <SafeAreaViewExample />;
      break;
    case 'hooks':
      content = <HooksExample />;
      break;
    // case 'react-navigation':
    //   content = <ReactNavigationExample />;
    //   break;
    case 'native-stack':
      content = <ReactNavigationNativeStackExample />;
      break;
    default:
      content = (
        <View
          style={{
            flex: 1,
            alignItems: 'center',
            justifyContent: 'center',
            padding: 24,
            backgroundColor: 'white',
          }}
        >
          <Text style={{ textAlign: 'center', fontSize: 14 }}>
            Open the dev menu to choose an example
          </Text>
        </View>
      );
      break;
  }

  return (
    <>
      <StatusBar
        hidden={statusBarHidden}
        backgroundColor="rgba(0, 0, 0, 0.3)"
      />
      {content}
    </>
  );
}
