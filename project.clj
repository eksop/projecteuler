(defproject projecteuler "0.1.0-SNAPSHOT"
  :description "Solutions to projecteuler problems"
  :url "https://github.com/xitkov/projecteuler"
  :license {:name "Eclipse Public License"
            :url "http://www.eclipse.org/legal/epl-v10.html"}
  :dependencies [[org.clojure/clojure "1.7.0"]
                 [ring "1.4.0"]]
  ;; :plugins [[lein-ring "0.8.5"]]
  :main ^:skip-aot projecteuler.core
  :target-path "target/%s"
  :profiles {:uberjar {:aot :all}})
