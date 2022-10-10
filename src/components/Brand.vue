

<template>
  <div id="brand">
    <div class="content">
      <RouterLink to="/" rel="start">
        <p class="author">{{ author }}</p>
        <h1>{{ CNName }}</h1>
      </RouterLink>
      <p class="description">{{ description }}</p>
    </div>
  </div>
</template>
<script setup>
import { RouterLink } from "vue-router";
import config from "../../public/config";
const { author, CNName, description } = config;
</script>

<style lang='scss' scoped>
#brand {
  position: fixed;
  padding: 3rem 5rem 0;
  text-align: center;
  width: 100%;
  height: 50vh;
  min-height: 10rem;
  z-index: -1;
}

#brand,
#brand .content {
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  animation: slideDownIn 0.3s;
}

#brand .author {
  font-family: "Fredericka the Great", Mulish, -apple-system, "PingFang SC",
    "Microsoft YaHei", sans-serif;
  font-size: 3.5em;
  line-height: 1.2;
}

#brand h1 {
  font-size: 2.5em;
  letter-spacing: 0.125rem;
}

#brand .author + h1 {
  margin: 0.625rem 0;
}

#brand .description {
  display: flex;
  font-size: 0.875em;
  margin: 0;
}

@media (min-width: 768px) and (max-width: 991px) {
  #brand .description {
    font-size: 0.8125em;
  }
}

@media (max-width: 767px) {
  #brand {
    padding: 3rem 0.5rem 0;
  }

  #brand h1 {
    font-size: 1.5em;
  }

  #brand .description {
    font-size: 0.75em;
  }
}

@media (max-width: 413px) {
  #brand .author {
    font-size: 2.5em;
  }
}
</style>