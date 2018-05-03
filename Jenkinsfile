pipeline {
    agent {
        docker {
            image 'gcc'
        }
    }
    stages {
        stage('Build') {
            steps {
                sh 'make -C makeDirectoryName'
            }
        }
        stage('Test') {
            steps {
                sh 'make -C makeDirectoryName test'
            }
        }
    }
}

