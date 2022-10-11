<template>
  <div id="sidebar" :class="isSidebar ? 'on' : ''">
    <div class="side--links g--animation" data-title="站点概览">
      <router-link
        class="link"
        :to="link.url"
        v-for="link of sidebar.localPath"
        :key="link"
        :class="link.name"
      >
        <i class="ic" :class="link.icon"></i>
        <!-- <span class="count">{{ sidebar.articlesNum }}</span>
        <span class="name">文章</span>-->
      </router-link>

      <a
        v-for="link of sidebar.socialLinks"
        :key="link"
        :href="link.url"
        rel="noopener external nofollow noreferrer"
        target="_blank"
        class="link"
        :class="link.name"
        :title="link.url"
      >
        <i class="ic" :class="link.icon"></i>
      </a>
    </div>
  </div>
</template>
<script setup>
import { toRefs } from "vue";
import config from "../../public/config";
import { store } from "@/stores/store.js";
import { RouterLink } from "vue-router";
const { sidebar } = config;
const state = store();
const { isSidebar } = toRefs(state);
</script>

<style lang='scss' scoped>
#sidebar {
  display: flex;
  align-items: center;
  justify-content: center;
}
@media (min-width: 991px) {
  #sidebar {
    position: fixed;
    left: 0;
    top: 0;
  }
}

.side--links {
  display: flex;
  flex-direction: column;
  padding: 10px;
}

.side--links {
  text-align: center;
}

.side--links .link {
  display: inline-block;
  width: 1.875rem;
  height: 1.875rem;
  line-height: 1.875rem;
  text-align: center;
  position: relative;
  overflow: hidden;
  border-radius: 38%;
}

.side--links .link i {
  font-size: 1.4em;
  vertical-align: middle;
  transform: scale(0.8);
}

.side--links .link::before {
  top: 90%;
  left: -110%;
  content: "";
  width: 120%;
  height: 120%;
  position: absolute;
  transform: rotate(45deg);
}

.side--links .link i,
.side--links .link::before {
  transition: all 0.35s cubic-bezier(0.31, -0.105, 0.43, 1.59) 0s;
}

.side--links .link:focus::before,
.side--links .link:hover::before {
  top: -10%;
  left: -10%;
}

.side--links .link.normal::before {
  background-color: var(--color-morandi-purple);
}

.side--links .link.normal i {
  color: var(--color-morandi-purple);
}

.side--links .link.github::before {
  background-color: #191717;
}

.side--links .link.github i {
  color: #191717;
}

.side--links .link.twitter::before {
  background-color: #00aff0;
}

.side--links .link.twitter i {
  color: #00aff0;
}

.side--links .link.zhihu::before {
  background-color: #1e88e5;
}

.side--links .link.zhihu i {
  color: #1e88e5;
}

.side--links .link.music::before {
  background-color: #e60026;
}

.side--links .link.music i {
  color: #e60026;
}

.side--links .link.telegram::before {
  background-color: #32afed;
}

.side--links .link.telegram i {
  color: #32afed;
}

.side--links .link.about::before {
  background-color: #3b5998;
}

.side--links .link.about i {
  color: #3b5998;
}

.side--links .link:focus i,
.side--links .link:hover i {
  color: var(--grey-0);
  transform: scale(1);
}
</style>