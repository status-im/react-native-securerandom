import { NativeModules } from 'react-native';
import { toByteArray } from 'base64-js';

const { RNSecureRandom } = NativeModules;

export function generateSecureRandom(length) {
    if (Platform.OS !== 'ios' && Platform.OS !== 'android' && Platform.OS !== 'desktop') {
        throw Error('react-native-securerandom is currently only available for iOS, Android and Desktop');
    }

    return RNSecureRandom.generateSecureRandomAsBase64(length).then(base64 => toByteArray(base64));
}
