import { requireNativeComponent } from 'react-native';
import type { NativeSafeAreaViewProps } from './SafeArea.types';

export const SafeAreaView =
  requireNativeComponent<NativeSafeAreaViewProps>('RNCSafeAreaView');
